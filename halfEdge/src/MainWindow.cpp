#include <MainWindow.h>
#include <QPainter>
#include <Qt>
#include <CommandQueue.h>
#include <QDebug>
MainWindow::MainWindow()
{
    //conecta os icones com suas imagem nos resources
    QIcon zi(":zoom-in");
    QIcon zo(":zoom-out");
    QIcon op(":open");
    QIcon al(":arrow-left");
    QIcon au(":arrow-up");
    QIcon ar(":arrow-rigth");
    QIcon ad(":arrow-down");
    QIcon a(":aresta");
    QIcon v(":vertice");
    QIcon f(":face");

    fila = new CommandQueue();
    centralpanel = new RenderPanel(fila);
    setCentralWidget(centralpanel);

    tb = new QToolBar("Tool Bar", this);
    fd = new QFileDialog(this, Qt::Window);
    fd->setDirectory("../../halfedge/resources");
    fd->setFilter("*.ply");
    
    fdSave = new QFileDialog(this, Qt::Window);
    fdSave->setDirectory("../../halfedge/resources");
    fdSave->setFilter("*.ply");
    
    connect(tb, SIGNAL(actionTriggered( QAction * )), this, SLOT(clicou(QAction*)));
    connect(fd, SIGNAL(fileSelected(const QString &)), centralpanel, SLOT(recebeArquivo(const QString &)));
    
    //atribuicoes da forma Qaction = Qtoolbar-> addAction (QIcon,Const char *)

    open = tb->addAction(op,"");
    tb->addSeparator();
    zoomIn = tb->addAction(zi, "");
    zoomOut = tb->addAction(zo, "");
    tb->addSeparator();
    panU = tb->addAction(au, "");
    panL = tb->addAction(al, "");
    panR = tb->addAction(ar, "");
    panD = tb->addAction(ad, "");
    tb->addSeparator();
    vertice = tb->addAction(v,"");
    aresta = tb->addAction(a,"");
    face = tb->addAction(f, "");
    del = tb->addAction("deleta");
    vdv = tb->addAction("VDV");
    add = tb->addAction("Adicionar");
    salvar = tb->addAction("Salvar");

    addToolBar(Qt::LeftToolBarArea, tb);

    connect(centralpanel, SIGNAL(atualizaMain()), this, SLOT(update()));

    setWindowTitle("Trabalho 2 2011-2 Bruno Campos e Thalles Rodrigues");
    setFixedSize(1024,768);
}


//declarado como slot
void MainWindow::clicou(QAction* a)
{
    if(a == open)
        fd->open();
    else if(a == zoomIn)
    {
        fila->produz(INCZOOM);
    }else if (a == zoomOut)
    {
        fila->produz(DECZOOM);
    }else if (a == panU)
    {
        fila->produz(DECY);
    }else if (a == panL)
    {
        fila->produz(DECX);
    }else if (a == panD)
    {
        fila->produz(INCY);
    }else if(a == panR)
    {
        fila->produz(INCX);
    }else if(a == vertice)
    {
        fila->produz(PONTOS);
    }else if(a == aresta)
    {
        fila->produz(ARESTAS);
    }else if(a == face)
    {
        fila->produz(FACES);
    }else if(a ==del)
    {
        fila->produz(DELETA);
    }else if(a == vdv)
    {
        fila->produz(VDV);
    }else if (a == add)
    {
        fila->produz(ADICIONA);
    }else if (a == salvar) {
        QString filename = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                         "",
                                                         tr("Polygon File Format (*.ply )"));
        centralpanel->recebeArquivoSalvar(filename);
    }
}

void MainWindow::update(void)
{
	repaint();
}
