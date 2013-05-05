//---------------------------------------------------------------------------

#include <vcl.h>
#include "NeuroLib.h"
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LearnClick(TObject *Sender)
{
	int neurons_in_layer[3] = {2,4,1};
	int n_of_layers = 3;
	NeuralNetwork* net = new NeuralNetwork(neurons_in_layer, n_of_layers);

	Memo1->Lines->Add("number of layers: " + AnsiString(net->getNumberOfLayers()));
	for(int i = 0 ; i < net->getNumberOfLayers(); i++){
		Memo1->Lines->Add("number of neurons in layer #" + AnsiString(i)+": " + AnsiString(net->getNumberOfNeuronsInLayer(i)));
	}

	int learn_array[10] = {0,1,2,3,4,5,6,7,8,9};
	for (int i = 0; i < 10; i++) {
		Memo1->Lines->Add("-------------------------------");
		Memo1->Lines->Add("learn epoch #"+AnsiString(i));
		int val1 = learn_array[rand() % 10];
		int val2 = learn_array[rand() % 10];
		int sum = val1 + val2;
		int input_data[2] = {val1, val2};
		net->LearnEpoch(input_data, sum, Memo1);
	}
}
//---------------------------------------------------------------------------
