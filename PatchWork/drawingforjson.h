#ifndef DRAWINGFORJSON_H
#define DRAWINGFORJSON_H


class DrawingForJSON
{
public:
    DrawingForJSON();

    const QList<ObjectInterface> &shapes() const;
    void setShapes(const QList<ObjectInterface> &shapes);

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

private:
    QList<ObjectInterface> mShapes;
};

#endif // DRAWINGFORJSON_H
