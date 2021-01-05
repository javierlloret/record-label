#include "MiniCppUnit.hxx"

#include "Estil.hxx"
#include "Usuari.hxx"
#include "Canso.hxx"
#include "MailStub.hxx"
#include "NovetatsWeb.hxx"
#include "Artista.hxx"
#include "Sms.hxx"
#include "Facade.hxx"
#include "EstrategiaNotificacio.hxx"
#include "Postmail.hxx"

class TestsUnitarisSubscripcions : public GrupDeTests<TestsUnitarisSubscripcions>
{
public:
	GRUP_DE_TESTS(TestsUnitarisSubscripcions)
	{
		CAS_DE_TEST( testUsuari_subscritAEstil );
		CAS_DE_TEST( testNovetatsWeb_subscritAEstil );
		CAS_DE_TEST( test2UsuarisINovetatsWeb_subscritsAEstil );
		CAS_DE_TEST( test2Usuaris_canviantOrdre_INovetatsWeb_subscritsAEstil );
		CAS_DE_TEST( testUsuariINovetatsWeb_subscritsAArtista );
		CAS_DE_TEST( testUsuari_activaRebreSms );
		CAS_DE_TEST( testUsuari_activaRebreSms2 );
		CAS_DE_TEST( testSMS_enviaNotificacio );
		CAS_DE_TEST( testSMS_enviaNotificacio_esVirtual );
		CAS_DE_TEST( testUsuariNotificaAmb_PassantUnEmail );
		CAS_DE_TEST( testUsuariNotificaAmb_PassantUnPostmail );
	}
	void tearDown()
	{
		MailStub::laInstancia().esborraEnviats();
		SmsStub::laInstancia().esborraEnviats();
	}

	void testUsuari_subscritAEstil()
	{
		Estil estil("patxanga");
		Usuari usuari("ramon", "ramon@brauli.com");
		estil.subscriu(usuari);

		Canso canso;
		canso.titol("tractor groc");
		estil.notificaNovaCanso( canso, estil.nom() );
		ASSERT_IGUALS(
			"A: ramon@brauli.com\n"
			"Assumpte: [SingAlong] novetat patxanga\n"
			"Missatge: Nova canso patxanga: tractor groc\n",
			MailStub::laInstancia().mailsEnviats() );
	}

	void testNovetatsWeb_subscritAEstil()
	{
		Estil estil("patxanga");
		NovetatsWeb web;
		estil.subscriu( web );
		Canso canso;
		canso.titol("tractor groc");
		estil.notificaNovaCanso( canso, estil.nom() );
		ASSERT_IGUALS(
			"novetat patxanga. Nova canso: tractor groc\n",
			web.log() );

		ASSERT_IGUALS("", MailStub::laInstancia().mailsEnviats() );
	}

	void test2UsuarisINovetatsWeb_subscritsAEstil()
	{
		Estil estil("patxanga");
		NovetatsWeb web;
		estil.subscriu( web );
		Usuari ramon("ramon","ramon@brauli.com");
		Usuari brauli("brauli", "brauli@brauli.com");
		estil.subscriu( ramon );
		estil.subscriu( brauli );

		Canso canso;
		canso.titol("tractor groc");
		estil.notificaNovaCanso( canso, estil.nom() );

		ASSERT_IGUALS(
			"novetat patxanga. Nova canso: tractor groc\n",
			web.log() );
		ASSERT_IGUALS(
			// Notar que estan ordentats alfab�icament
			"A: brauli@brauli.com\n"
			"Assumpte: [SingAlong] novetat patxanga\n"
			"Missatge: Nova canso patxanga: tractor groc\n"

			"A: ramon@brauli.com\n"
			"Assumpte: [SingAlong] novetat patxanga\n"
			"Missatge: Nova canso patxanga: tractor groc\n",
			MailStub::laInstancia().mailsEnviats() );
	}

	void test2Usuaris_canviantOrdre_INovetatsWeb_subscritsAEstil()
	{
		Estil estil("patxanga");
		NovetatsWeb web;
		estil.subscriu( web );
		Usuari brauli("brauli", "brauli@brauli.com");
		Usuari ramon("ramon","ramon@brauli.com");
		estil.subscriu( ramon );
		estil.subscriu( brauli );

		Canso canso;
		canso.titol("tractor groc");
		estil.notificaNovaCanso( canso, estil.nom() );

		ASSERT_IGUALS(
			"novetat patxanga. Nova canso: tractor groc\n",
			web.log() );
		ASSERT_IGUALS(
			// Notar que estan ordentats alfab�icament
			"A: brauli@brauli.com\n"
			"Assumpte: [SingAlong] novetat patxanga\n"
			"Missatge: Nova canso patxanga: tractor groc\n"

			"A: ramon@brauli.com\n"
			"Assumpte: [SingAlong] novetat patxanga\n"
			"Missatge: Nova canso patxanga: tractor groc\n",
			MailStub::laInstancia().mailsEnviats() );
	}

	void testUsuariINovetatsWeb_subscritsAArtista()
	{
		Artista ramoncin("Ramoncin");

		NovetatsWeb web;
		Usuari ramon("ramon", "ramon@brauli.com");

		ramoncin.subscriu(ramon);
		ramoncin.subscriu(web);

		Canso canso;
		canso.titol("soy rebelde");
		ramoncin.notificaNovaCanso( canso, ramoncin.nom() );

		ASSERT_IGUALS(
			"novetat Ramoncin. Nova canso: soy rebelde\n",
			web.log() );
		ASSERT_IGUALS(
			"A: ramon@brauli.com\n"
			"Assumpte: [SingAlong] novetat Ramoncin\n"
			"Missatge: Nova canso Ramoncin: soy rebelde\n",
			MailStub::laInstancia().mailsEnviats() );
	}
	
	void testUsuari_activaRebreSms()
	{
		Artista ramoncin("Ramoncin");
		Usuari usuari("toni", "toni@brauli.com");
		Canso canso;
		canso.titol("soy rebelde");

		ramoncin.subscriu(usuari);
		usuari.volRebreSms("656656565");
		ramoncin.notificaNovaCanso( canso, ramoncin.nom() );

		ASSERT_IGUALS(
			"",
			MailStub::laInstancia().mailsEnviats() );
		ASSERT_IGUALS(
			"SMS a 656656565: [SingAlong] Nova canso Ramoncin: soy rebelde\n",
			SmsStub::laInstancia().missatgesEnviats() );
	}
	
	void testUsuari_activaRebreSms2()
	{
		Artista ramoncin("Ramoncin");
		Artista rafael("Rafael");
		Usuari usuari("toni", "toni@brauli.com");
		Canso canso1;
		Canso canso2;
		canso1.titol("soy rebelde");
		canso2.titol("soy yo");
		
		ramoncin.subscriu(usuari);
		rafael.subscriu(usuari);
		usuari.volRebreSms("656656565");
		ramoncin.notificaNovaCanso( canso1, ramoncin.nom() );
		rafael.notificaNovaCanso( canso2, rafael.nom() );
		
		ASSERT_IGUALS(
			"",
			MailStub::laInstancia().mailsEnviats() );
		ASSERT_IGUALS(
			"SMS a 656656565: [SingAlong] Nova canso Rafael: soy yo\n"
			"SMS a 656656565: [SingAlong] Nova canso Ramoncin: soy rebelde\n",
			SmsStub::laInstancia().missatgesEnviats() );
	}	
	

// Testos d'estrategies concretes notificacio
	void testSMS_enviaNotificacio()
	{
			
		Usuari usuari("toni", "toni@brauli.com");
		usuari.mobil("656656565");
		
		Canso canso;
		canso.titol("soy rebelde");

		Sms sms;
		sms.enviaNotificacio(usuari,canso,"Ramoncin");
		
		ASSERT_IGUALS(
			"SMS a 656656565: [SingAlong] Nova canso Ramoncin: soy rebelde\n",
			SmsStub::laInstancia().missatgesEnviats() );
	}	

	void testSMS_enviaNotificacio_esVirtual()
	{
	
		Usuari usuari("toni", "toni@brauli.com");
		usuari.mobil("656656565");
		
		Canso canso;
		canso.titol("soy rebelde");
	
		std::string origen="Ramoncin";
		
		Sms sms;
		
		EstrategiaNotificacio& estrategiaNotificacio = sms;
				
		estrategiaNotificacio.enviaNotificacio(usuari,canso,origen);
		
		ASSERT_IGUALS(
			"SMS a 656656565: [SingAlong] Nova canso Ramoncin: soy rebelde\n",
			SmsStub::laInstancia().missatgesEnviats() );
	
	}	



	void testUsuariNotificaAmb_PassantUnSms()
	{

		Artista ramoncin("Ramoncin");
		Usuari usuari("toni", "toni@brauli.com");
		usuari.mobil("555555555");
		Canso canso;
		canso.titol("soy rebelde");

		ramoncin.subscriu(usuari);
		usuari.notificaAmb(new Sms);

		ramoncin.notificaNovaCanso( canso, ramoncin.nom() );

		ASSERT_IGUALS(
			"",
			MailStub::laInstancia().mailsEnviats() );
		ASSERT_IGUALS(
			"SMS a 656656565: [SingAlong] Nova canso Ramoncin: soy rebelde\n",
			SmsStub::laInstancia().missatgesEnviats() );

	}	
	
	void testUsuariNotificaAmb_PassantUnEmail()
	{

		Artista ramoncin("Ramoncin");
		Usuari usuari("toni", "toni@brauli.com");
		usuari.mobil("555555555");
		Canso canso;
		canso.titol("soy rebelde");

		ramoncin.subscriu(usuari);
		usuari.notificaAmb(new Email);

		ramoncin.notificaNovaCanso( canso, ramoncin.nom() );

		ASSERT_IGUALS(
			"",
			SmsStub::laInstancia().missatgesEnviats() );
		ASSERT_IGUALS(
			"A: toni@brauli.com\n"
			"Assumpte: [SingAlong] novetat Ramoncin\n" 
			"Missatge: Nova canso Ramoncin: soy rebelde\n",
			MailStub::laInstancia().mailsEnviats() );

	}	
				
	void testEmail_enviaNotificacio_esVirtual()
	{
	
		Usuari usuari("toni", "toni@brauli.com");
		usuari.mobil("656656565");
		
		Canso canso;
		canso.titol("soy rebelde");
	
		std::string origen="Ramoncin";
		
		Email email;
		
		EstrategiaNotificacio& estrategiaNotificacio = email;
				
		estrategiaNotificacio.enviaNotificacio(usuari,canso,origen);
		
		ASSERT_IGUALS(
			"A: toni@brauli.com\n"
			"Assumpte: [SingAlong] novetat Ramoncin\n" 
			"Missatge: Nova canso Ramoncin: soy rebelde\n",
			MailStub::laInstancia().mailsEnviats() );
	}	
	
	void testUsuariNotificaAmb_PassantUnPostmail()
	{
		Artista ramoncin("Ramoncin");
		Usuari usuari("toni", "toni@brauli.com");
		usuari.adresa("dos de maig, 340 entlo 4. Barcelona");
		Canso canso;
		canso.titol("soy rebelde");

		ramoncin.subscriu(usuari);
		usuari.notificaAmb(new Postmail);

		ramoncin.notificaNovaCanso( canso, ramoncin.nom() );

		ASSERT_IGUALS(
			"",
			SmsStub::laInstancia().missatgesEnviats() );
		ASSERT_IGUALS(
			"",
			MailStub::laInstancia().mailsEnviats() );
		ASSERT_IGUALS(
			"A: dos de maig, 340 entlo 4. Barcelona\n"
			"Assumpte: [SingAlong] novetat Ramoncin\n" 
			"Missatge: Nova canso Ramoncin: soy rebelde\n",
			PostmailStub::laInstancia().postmailsEnviats() ); 
	}	
};

void executaTestsUnitarisSubscripcions()
{
	TestsUnitarisSubscripcions().testeja();
}
