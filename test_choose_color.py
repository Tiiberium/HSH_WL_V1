import PySimpleGUI as sg
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

layout = [
    [sg.Text('Введите номер карты'), sg.InputText(), 
     
     ],
    [sg.Text('Выберите зону'), sg.InputText(),
     sg.Checkbox('1й этаж'),
     sg.Checkbox('2й этаж'),
     sg.Checkbox('3й этаж')
     
     ],
    [sg.Output(size=(88, 20))],
    [sg.Submit(), sg.Cancel()]
]
window = sg.Window('HSH_IMPORT_CARDS_V1', layout)
while True:                             # The Event Loop
    event, values = window.read()
    # print(event, values) #debug
    if event in (None, 'Exit', 'Cancel'):
        break
