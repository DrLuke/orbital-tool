#include <gtkmm.h>
#include <mainwin.hpp>

int main(int argc, char* argv[])
{
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.orbit.orbitgui");
	
	Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create();
	try
	{
		builder->add_from_file("ui/ui.glade");
	}
	catch(const Glib::FileError &e)
	{
		std::cerr << "File error: " << e.what() << std::endl;
		return 1;
	}
	catch(const Glib::MarkupError &e)
	{
		std::cerr << "Markup error: " << e.what() << std::endl;
		return 1;
	}
	catch(const Gtk::BuilderError& ex)
  	{
		std::cerr << "BuilderError: " << ex.what() << std::endl;
		return 1;
	}

	mainWin* window = NULL;
	builder->get_widget_derived("mainWindow", window);



	
	return app->run(*window);

	return 0;
}
