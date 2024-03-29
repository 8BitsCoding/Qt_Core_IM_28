#include <QtCore/QCoreApplication>

#include <qdebug.h>

/*
HEX
*/

QString makeData() {
	QString data;
	for (int i = 0; i < 10; i++) {
		data.append("Hello\r\n");
	}

	return data;
}

int main(int argc, char* argv[])
{
	QCoreApplication a(argc, argv);

	QString data = makeData();
	QByteArray bytes(data.toLatin1());
	QByteArray encoded = bytes.toHex();
	QByteArray decode = encoded.fromHex(encoded);

	qInfo() << "Encoded: " << encoded;
	qInfo("");
	qInfo() << "Decoded: " << decode;


	return a.exec();
}