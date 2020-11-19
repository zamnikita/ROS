#ifndef STANDARD_MODEL_DESCRIPTION_H
#define STANDARD_MODEL_DESCRIPTION_H

struct element
{
	std::string name;
	std::string type;
	std::string mass;
	std::string charge;
	std::string spin;
};

element standart_model_description[4][5] = 
{	{{"up","quark","2.2 MeV/c^2","2/3","1/2"}, {"charm","quark","1.28 GeV/c^2","2/3","1/2"}, {"top","quark","173.1 GeV/c^2","2/3","1/2"}, 				{"gluon","gauge boson","0","0","1"}, {"higgs","scalar boson","124.97 GeV/c^2","0","0"}},
	{{"down","quark","4.7 MeV/c^2","-1/3","1/2"}, {"strange","quark","96 MeV/c^2","-1/3","1/2"}, 
			{"bottom","quark","4.18 GeV/c^2","-1/3","1/2"}, {"photon","gauge boson","0","0","1"}, {"","","","",""}},
	{{"electron","lepton","0.511 MeV/c^2","-1","1/2"}, {"muon","lepton","105.66 MeV/c^2","-1","1/2"},
			{"tau","lepton","1.7768 GeV/c^2","-1","1/2"},{"Z boson","gauge boson","91.19 GeV/c^2","0","1"},	{"","","","",""}},
	{{"electron neutrino","lepton","<1 eV/c^2","0","1/2"}, {"muon neutrino","lepton","<0.17 MeV/c^2","0","1/2"},
			{"tau neutrino","lepton","<18.2 MeV/c^2","-1","1/2"}, {"W boson","gauge boson","80.39 GeV/c^2","±1","1"}, 				{"","","","",""}}
};



#endif
