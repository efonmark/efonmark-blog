# -*- coding: utf-8 -*-
"""
1、安装库  pip install fitz
2、直接运行
"""
import fitz,os,glob

def getFileName(filepath):
    file_list = sorted(glob.glob("{}*.pdf".format(filepath) ),key=os.path.getmtime, reverse=False)
    return file_list

def pdf2img(pdfName):
    dir = pdfName.split('.',100)[0]
    print(dir)
    if not (os.path.isdir(dir)):
        os.makedirs(dir)
    #  打开PDF文件，生成一个对象
    doc = fitz.open(pdfName)

    for pg in range(doc.pageCount):
        page = doc[pg]
        rotate = int(0)
        # 每个尺寸的缩放系数为4，这将为我们生成分辨率提高16倍的图像。
        # 分辨率越高，图像越清晰，图片大小越大。
        zoom_x = 4.0
        zoom_y = 4.0
        trans = fitz.Matrix(zoom_x, zoom_y).preRotate(rotate)
        pm = page.getPixmap(matrix=trans, alpha=False)
        pm.writePNG('{}/{}.png'.format(dir, pg))

def pdfs2img(dir):
    for each_file in getFileName(dir):
        pdf2img(each_file)
        print("each_file 2 pdf done.")

if __name__ == "__main__":  #这里可以判断，当前文件是否是直接被python调用执行
    pdfs2img('D:/02-python/pdf2img/')