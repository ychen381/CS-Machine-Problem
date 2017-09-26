
#include "StickerSheet.h"
#include <iostream>
#include "assert.h"

using namespace cs225;

int main() {
  /*Image alma, I, Sticker1, Sticker2, Sticker3, Sticker4;

  alma.readFromFile("alma.png");
  I.readFromFile("i.png");
  //Sticker1.readFromFile("sticker1.png");

  //Sticker2.readFromFile("Sticker2.png");
  //Sticker2.scale(0.7);
  //Sticker3.readFromFile("Sticker3.png");
  //Sticker1.scale(0.4);
  StickerSheet sheet(alma, 5);
  std::cout << "sheet(alma,5)" << '\n';
  StickerSheet sheet1(sheet);
  std::cout << "sheet1klkl" << '\n';

  for(int index =-3; index < 15; index++)
  {std::cout << "start for" << '\n';
    sheet1.removeSticker(index);

    Image* Test1 = sheet1.getSticker(index);

    Image* Test2 = sheet.getSticker(index);
    assert(Test1 == Test2);
    assert(sheet.translate(index, 100, 100) == 0);
  }
  std::cout << "for 30" << '\n';
  //sheet.addSticker(Sticker1, 515, 55);
  //sheet.addSticker(Sticker2, 375, 3);
  //sheet.addSticker(Sticker3, 200, 120);
  //alma = sheet.render();
  //alma.writeToFile("23y.png");
  for(int index = -3; index < 15; index++)
  {
    sheet.removeSticker(index);
    Image* Test = sheet.getSticker(index);
    assert(Test == NULL);
    assert(sheet.translate(index, 100, 100) == 0);
  }
  assert(sheet.render() == alma);
  std::cout << "render success" << '\n';


  assert(sheet.addSticker(I, 20, 100) == 0);
  std::cout << "add 20 100" << '\n';
  assert(sheet.addSticker(I, 100, 200) == 1);
  std::cout << "add 100 200" << '\n';
  assert(sheet.addSticker(I, 100, 20) == 2);
  std::cout << "add 100 20" << '\n';

  assert(*(sheet.getSticker(2)) == I);
  assert(sheet.getSticker(3) == NULL);
  assert(sheet.getSticker(6) == NULL);
  assert(sheet.translate(3, 1500, 200) == 0);
  assert(sheet.translate(0, 20, 100) == 1);

  std::cout << "translate(0,20,100)" << '\n';

  assert(sheet.addSticker(I, 500, 200) == 3);
  assert(sheet.addSticker(I, 900, 50) == 4);

    Image* Test = sheet.getSticker(0);
    assert(*Test == I);
    std::cout << "getStickerRight" << '\n';
      assert(*(sheet.getSticker(0)) == I);

  assert(sheet.getSticker(100) == NULL);
  std::cout << "getSticker==NULL" << '\n';
  assert(*(sheet.getSticker(0)) == I);
  assert(sheet.getSticker(-2) == NULL);
  std::cout << "getSticker==NULL" << '\n';

  assert(sheet.addSticker(I, 700, 50) == -1);
  std::cout << "add(700,50)" << '\n';
  assert(*(sheet.getSticker(0)) == I);
  Sticker1 = sheet.render();
  std::cout << "render sucess" << '\n';
  assert(*(sheet.getSticker(0)) == I);
  assert(*(sheet.getSticker(1)) == I);
  std::cout << "get(1)" << '\n';
  assert(*(sheet.getSticker(2)) == I);
  std::cout << "get(2)" << '\n';
  assert(*(sheet.getSticker(0)) == I);
  std::cout << "get(0)" << '\n';

  sheet.removeSticker(0);assert(sheet.getSticker(0) == NULL);
  sheet.removeSticker(2);assert(sheet.getSticker(2) == NULL);
  sheet.removeSticker(4);assert(sheet.getSticker(4) == NULL);
  sheet.removeSticker(7);assert(sheet.getSticker(7) == NULL);

  assert(sheet.addSticker(I, 20, 100) == 0);
  assert(sheet.addSticker(I, 100, 20) == 2);
  assert(sheet.addSticker(I, 900, 50) == 4);

  std::cout << "addSticker(I,900,50)" << '\n';
  assert(sheet.translate(3, 300, 20) == 1);
  assert(sheet.translate(5,200,30) == 0);
  assert(sheet.render() != Sticker1);
std::cout << "render sticker1" << '\n';
  assert(sheet.translate(3, 500, 200) == 1);
  assert(sheet.render() == Sticker1);

  assert(sheet.translate(3, 300, 20) == 1);
  assert(sheet.addSticker(I, 700,200) == -1);

  StickerSheet sheets(alma, 6);
  std::cout << "sheets(alma,66)" << '\n';
  sheets = sheet;
  std::cout << "=" << '\n';
  for(int index = -2; index < 10; index++)
  {
    Image* Test1 = sheet.getSticker(index);
    Image* Test2 = sheets.getSticker(index);
    if(Test1 != NULL){
    assert(*Test1 == *Test2);}
    if(Test1 == NULL){
    assert(Test2 == NULL);}
  }
std::cout << "for101" << '\n';



*/
Image mou; mou.readFromFile("mou.png");
Image flower;    flower.readFromFile("flower.png");
Image arrow;      arrow.readFromFile("arrow.png");
Image Aloe; Aloe.readFromFile("Aloe.png");

StickerSheet sheet(mou, 100);
sheet.addSticker(flower, 20, 200);


sheet.addSticker(arrow, 120, 200);
sheet.addSticker(Aloe, 140, 200);

  Image Sticker1 = sheet.render();
  Sticker1.writeToFile("myImage.png");
  return 0;
}/*

  alma = I;

  assert(Sticker1 == sheet.render());
  assert(Sticker1 == sheets.render());

  alma.readFromFile("alma.png");

  I = Sticker1;
  assert(Sticker1 == sheet.render());
  assert(Sticker1 == sheets.render());

  I.readFromFile("i.png");

  sheet.removeSticker(3);
  sheet.removeSticker(-10);
  sheet.removeSticker(20);

  assert(sheet.translate(3, 1300, 1020) == 0);
  assert(sheet.translate(3, 300, 20) == 0);
  assert(sheets.getSticker(3) != NULL);
  assert(sheet.getSticker(3) == NULL);

  Sticker1 = sheet.render();

  StickerSheet sheets1(sheet);
  for(int index = -2; index < 10; index++)
  {
    Image* Test1 = sheet.getSticker(index);
    Image* Test2 = sheets.getSticker(index);
    if(Test1 != NULL){
    assert(*Test1 == *Test2);}
    if(Test1 == NULL && index != 3){
    assert(Test2 == NULL);}
    if(Test1 == NULL && index == 3){
    assert(Test2 != NULL);}
  }

  Image* a = sheet.getSticker(3);
  Image* a1 = sheets1.getSticker(3);
  assert(a == a1);

  assert(sheet.addSticker(I, 500, 200) == 3);
  std::cout << "line73" << '\n';
  assert(sheets1.getSticker(3) != sheet.getSticker(3));
  std::cout << "line75" << '\n';
  assert(sheets1.getSticker(3)== NULL && *(sheet.getSticker(3)) == I);
std::cout << "line 77" << '\n';
  //a1->writeToFile("123.png");
  assert(sheets.getSticker(10) == NULL);
std::cout << "getsticker all right" << '\n';
  sheet.changeMaxStickers(10);
  std::cout << "changmaxstickers(10)" << '\n';
  for(int index = 0; index < 5; index++)
  {
    Image* Test = sheet.getSticker(index);
    assert(*Test == I);
  }
  for(int index = 5; index < 15; index++)
  {
    Image* Test = sheet.getSticker(index);
    assert(Test == NULL);
  }

  assert(sheet.getSticker(10) == NULL);
  assert(sheet.getSticker(9) == NULL);
  //alma = sheet.render();
  //copy_ = alma;
  //alma.writeToFile("23x.png");
  //copy_.writeToFile("23y.png");
  sheet.removeSticker(3);
  sheet.removeSticker(20);
  for(int index = -5; index < 30; index++)
  {
    Image* Test1 = sheet.getSticker(index);
    Image* Test2 = sheets1.getSticker(index);
    if(Test1 == NULL){
    assert(Test1 == Test2);}
    else{
    assert(*Test1 == I && *Test2 == I && *Test1 == *Test2);}
  }

  Sticker2 = sheet.render();
  assert(Sticker1 == Sticker2);

  StickerSheet Sheet_test(sheet);
  for(int index = -5; index < 30; index++)
  {
    Image* Test1 = sheet.getSticker(index);
    Image* Test2 = Sheet_test.getSticker(index);
    if(Test1 == NULL){
    assert(Test1 == Test2);}
    else{
    assert(*Test1 == I && *Test2 == I && *Test1 == *Test2);}
  }

  assert(Sheet_test.addSticker(I, 300, 20) == 3);
  for(int index = -5; index < 30; index++)
  {
    Image* Test1 = sheets.getSticker(index);
    Image* Test2 = Sheet_test.getSticker(index);
    if(Test1 == NULL){
    assert(Test1 == Test2);}
    else{
    assert(*Test1 == I && *Test2 == I && *Test1 == *Test2);}
  }
  assert(Sheet_test.render() == sheets.render());

  Sheet_test = sheets1;
  for(int index = -5; index < 30; index++)
  {
    Image* Test1 = sheet.getSticker(index);
    Image* Test2 = Sheet_test.getSticker(index);
    if(Test1 == NULL){
    assert(Test1 == Test2);}
    else{
    assert(*Test1 == I && *Test2 == I && *Test1 == *Test2);}
  }

  assert(sheet.addSticker(I, 300, 20) == 3);
  assert(sheet.addSticker(I, 20, 100) == 5);
  assert(sheet.addSticker(I, 100, 200) == 6);
  assert(sheet.addSticker(I, 100, 20) == 7);
  assert(sheet.addSticker(I, 300, 20) == 8);
  assert(sheet.addSticker(I, 900, 50) == 9);
  assert(sheet.addSticker(I, 700, 50) == -1);

  assert(sheet.translate(10, 300, 20) == 0);
  assert(sheet.translate(-2, 300, 20) == 0);
  assert(sheet.translate(7, 300, 20) == 1);
  assert(sheet.translate(7, 100, 20) == 1);

  assert(sheet.render() == Sticker4);

  for(int index = 0; index <5; index++)
  {
    sheet.removeSticker(index);
  }
  assert(sheet.render() == Sticker4);
  assert(sheet.render() == sheets.render());

  sheet.removeSticker(8);
  assert(sheet.render() == sheets1.render());
  //alma.writeToFile("23y.png");

  alma.readFromFile("alma.png");

  StickerSheet* delete_sheet = new StickerSheet(sheets);
  *delete_sheet = sheet;
  delete delete_sheet;

  delete_sheet = new StickerSheet(sheet);
  delete delete_sheet;

  sheet.changeMaxStickers(0);
  //(sheet.render()).writeToFile("output2.png");
  assert(sheet.render() == alma);
  for(int index = -3; index < 15; index++)
  {
    assert(sheet.addSticker(I, 700, 50) == -1);
    sheet.removeSticker(index);
    Image* Test = sheet.getSticker(index);
    assert(Test == NULL);
  }

  StickerSheet* delete_sheet1 = new StickerSheet(sheets);
  *delete_sheet1 = sheet;
  delete delete_sheet1;

  delete_sheet1 = new StickerSheet(sheet);
  delete delete_sheet1;

  sheet.changeMaxStickers(5);
  assert(sheet.render() == alma);
  for(int index = -3; index < 15; index++)
  {
    sheet.removeSticker(index);
    Image* Test = sheet.getSticker(index);
    assert(Test == NULL);
  }

  StickerSheet* delete_sheet2 = new StickerSheet(sheet);
  delete delete_sheet2;

  for(int index = -3; index < 15; index++)
  {
    sheets.removeSticker(index);
    Image* Test = sheet.getSticker(index);
    assert(Test == NULL);
  }
  //(sheets.render().writeToFile("output3.png"));
  assert(sheets.render() == alma);

std::cout << "finally" << '\n';
  return 0;
}

*/
