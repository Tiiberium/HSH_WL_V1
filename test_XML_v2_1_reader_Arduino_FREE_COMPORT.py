import xml.etree.cElementTree as ET
from xml.dom import minidom
import time
import os
import serial

TSData = ET.Element("TSData")
Header = ET.SubElement(TSData, "Header")

ArduinoSerial = serial.Serial('COM3',9600) 
time.sleep(2)

print('KUAL TECH MANUAL CARD INSERT v1.1')



def main():
    new = ET.Element('TSdata')
    Header = ET.SubElement(new, 'Header')
    Version = ET.SubElement(Header, 'Version')
    Version.text = 'HSHIF25'
    Issuer = ET.SubElement(Header, 'Issuer')
    Issuer.text = '1'
    Receiver = ET.SubElement(Header, 'Receiver')
    Receiver.text = '1'
    ID = ET.SubElement(Header, 'ID')
    ID.text = '{}' .format(int(time.time()))
    WLR = ET.SubElement(new, 'WhitelistRecord')
    UTID = ET.SubElement(WLR, 'UTID')
    
        
    print('Введите номер карты:')
    def read():
        p = str(ArduinoSerial.readline().rstrip().decode("utf-8"))
        txt = p
        print(txt)
        return txt
    UTID.text = read()
    Coding = ET.SubElement(WLR, 'Coding')
    Coding.text = '33554432'
    Action = ET.SubElement(WLR, 'Action')
    Action.text = 'U'
    Permission = ET.SubElement(WLR, 'Permission')
    UPID = ET.SubElement(Permission, 'UPID')
    UPID.text = format(int(time.time()))
    TSPTICKET = ET.SubElement(Permission, 'TSProperty', Type="TICKETTYPE")
    TID = ET.SubElement(TSPTICKET, "ID")
    TID.text = '1'
    TSPAREA = ET.SubElement(Permission, 'TSProperty', Type="AREA")
    AID = ET.SubElement(TSPAREA, "ID")
    def choose_zone():
        print('Выберите зону доступа')
        print ('1 первый этаж')
        print ('2 второй этаж')
        print ('3 третий этаж')
        print ('4 четвертый этаж')
        AID.text = input()
        if AID.text > str(4):
            print('Ошибка зоны')
            return choose_zone()
        
        else:
            print ('Доступ разрешен')
            print('Сохранено. Номер карты: ' + str(UTID.text))
        
    choose_zone()  


    TSPEVENT = ET.SubElement(Permission, 'TSProperty', Type="EVENT")
    EID = ET.SubElement(TSPEVENT, "ID")
    EID.text = '1'
    TSPERSON = ET.SubElement(Permission, 'TSProperty', Type="PERSONCATEGORY")
    PID = ET.SubElement(TSPERSON, "ID")
    PID.text = '1'
    
    print()
    print()
    print()

    
    save_xml('whitelist_{}.txt' .format(int(time.time())), new)


def save_xml(filename, xml_code):
    xml_string = ET.tostring(xml_code).decode()
 
    xml_prettyxml = minidom.parseString(xml_string).toprettyxml()
    with open(filename, 'w') as xml_file:
        xml_file.write(xml_prettyxml)



 
if __name__ == '__main__':
    main()
while True:
    main()
