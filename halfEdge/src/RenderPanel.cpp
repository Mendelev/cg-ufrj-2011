#include <RenderPanel.h>

RenderPanel::RenderPanel(CommandQueue *c)
{  
    cmdq = c;
    fundolb = new QLabel(this);

    screenW = 1024;
    screenH = 768;

    Render *r = new Render(screenW, screenH, c);
    connect(r, SIGNAL(renderizado(const QImage &)), this, SLOT(update(const QImage &)), Qt::QueuedConnection);
    connect(this, SIGNAL(atualizaTamanho(int, int)), r, SLOT(updateScreen(int, int)), Qt::QueuedConnection);
    connect(this, SIGNAL(enviaArquivo(const QString &)), r, SLOT(recebeArquivo(const QString &)), Qt::QueuedConnection);
    connect(this, SIGNAL(enviaArquivoSalvar(const QString &)), r, SLOT(recebeArquivoSalvar(const QString &)), Qt::QueuedConnection);
    
    QImage tmp(screenW, screenH,QImage::Format_ARGB32_Premultiplied);
    QPainter p;
    p.begin(&tmp);
    p.fillRect(tmp.rect(), Qt::white);
    p.end();
    fundolb->setPixmap(QPixmap::fromImage(tmp));
    fundolb->show();

    repaint();
    r->start();
}

void RenderPanel::update(const QImage& screen)
{
    fundolb->setPixmap(QPixmap::fromImage(screen));
    fundolb->show();
    repaint();
    emit atualizaMain();
}

//vem quando o sinal do fileDialog seleciona um arquivo
void RenderPanel::recebeArquivo(const QString &filename)
{
    emit enviaArquivo(filename);
    //TODO THALLES
}

//vem quando o sinal do fileDialog seleciona um arquivo para salvar
void RenderPanel::recebeArquivoSalvar(const QString &filename)
{
    emit enviaArquivoSalvar(filename);
}

void RenderPanel::mouseReleaseEvent(QMouseEvent *event)
{

    if(event->x() >= 0 && event->y() >=0 && event->x() < fundolb->width() && event->y() < fundolb->height())
    {
        cmdq->produz(SELECT,event->x(), event->y());
    }
}
