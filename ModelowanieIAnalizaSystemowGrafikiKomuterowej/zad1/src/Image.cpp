#include "Image.h"

Image::Image(char *filename)
{

    typedef struct
    {
        unsigned char imageTypeCode;
        short int imageWidth;
        short int imageHeight;
        unsigned char bitCount;
        unsigned char *imageData;
    } TGAFILE;

    TGAFILE *tgaFile=new TGAFILE();
    FILE *filePtr;
    unsigned char ucharBad;
    short int sintBad;
    long imageSize;
    int colorMode;
    unsigned char colorSwap;

    // Open the TGA file.
    filePtr = fopen(filename, "rb");
    if (filePtr == NULL)
    {
        std::cout<<"NO IMAGE FILE\n";
    }

    // Read the two first bytes we don't need.
    fread(&ucharBad, sizeof(unsigned char), 1, filePtr);
    fread(&ucharBad, sizeof(unsigned char), 1, filePtr);

    // Which type of image gets stored in imageTypeCode.
    fread(&tgaFile->imageTypeCode, sizeof(unsigned char), 1, filePtr);

    // For our purposes, the type code should be 2 (uncompressed RGB image)
    // or 3 (uncompressed black-and-white images).
    if (tgaFile->imageTypeCode != 2 && tgaFile->imageTypeCode != 3)
    {
        fclose(filePtr);
        std::cout<<"ERROR IN IMAGETYPE\n";
    }

    // Read 13 bytes of data we don't need.
    fread(&sintBad, sizeof(short int), 1, filePtr);
    fread(&sintBad, sizeof(short int), 1, filePtr);
    fread(&ucharBad, sizeof(unsigned char), 1, filePtr);
    fread(&sintBad, sizeof(short int), 1, filePtr);
    fread(&sintBad, sizeof(short int), 1, filePtr);

    // Read the image's width and height.
    fread(&tgaFile->imageWidth, sizeof(short int), 1, filePtr);
    fread(&tgaFile->imageHeight, sizeof(short int), 1, filePtr);
    this->hres=tgaFile->imageWidth;
    this->vres=tgaFile->imageHeight;
    // Read the bit depth.
    fread(&tgaFile->bitCount, sizeof(unsigned char), 1, filePtr);

    // Read one byte of data we don't need.
    fread(&ucharBad, sizeof(unsigned char), 1, filePtr);

    // Color mode -> 3 = BGR, 4 = BGRA.
    colorMode = tgaFile->bitCount / 8;
    imageSize = tgaFile->imageWidth * tgaFile->imageHeight * colorMode;

    // Allocate memory for the image data.
    tgaFile->imageData = (unsigned char*)malloc(sizeof(unsigned char)*imageSize);

    m_pixels=new Colour[imageSize/4];


    // Read the image data.
    fread(tgaFile->imageData, sizeof(unsigned char), imageSize, filePtr);

    d_type::Buint counter=0;
    for(int i =0; i<imageSize; i+=4)
    {
        //B G R A
        // R G B A
        m_pixels[counter]=Colour((d_type::Bfloat)tgaFile->imageData[i+2]/255,
                                 (d_type::Bfloat)tgaFile->imageData[i+1]/255,
                                 (d_type::Bfloat)tgaFile->imageData[i]/255,
                                 (d_type::Bfloat)tgaFile->imageData[i+3]/255);
//m_pixels[counter]=Colour::randomColor();

        counter++;
    }
    std::cout<<counter<<"\n";
    fclose(filePtr);
    std::cout<<"IMAGE LOADED\n";
}

Image::~Image()
{
    //dtor
}
