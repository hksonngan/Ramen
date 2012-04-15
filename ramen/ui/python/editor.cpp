// Copyright (c) 2011 Esteban Tovagliari

#include<ramen/python/python.hpp>

#include<ramen/ui/python/editor.hpp>

#include<boost/python.hpp>

#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QPlainTextEdit>
#include<QPushButton>

#include<ramen/python/interpreter.hpp>

#include<ramen/undo/stack.hpp>

#include<ramen/ui/user_interface.hpp>
#include<ramen/ui/python/console.hpp>

namespace ramen
{
namespace ui
{
namespace python
{

editor_impl::editor_impl() : window_(0)
{
    window_ = new QWidget();
    window_->setWindowTitle( QObject::tr( "Python Editor"));

    QVBoxLayout *layout = new QVBoxLayout();

    edit_ = new QPlainTextEdit();
	edit_->setFont( ui::user_interface_t::Instance().get_fixed_width_code_font());

	edit_->setContextMenuPolicy( Qt::CustomContextMenu);
	connect( edit_, SIGNAL( customContextMenuRequested( const QPoint&)), this, SLOT( show_context_menu( const QPoint&)));

    layout->addWidget( edit_);

    QWidget *controls_ = new QWidget();

	QHBoxLayout *hlayout = new QHBoxLayout();
	hlayout->insertStretch( 0);

	QPushButton *button = new QPushButton( "Run");
	connect( button, SIGNAL( clicked()), this, SLOT( run()));
	hlayout->addWidget( button);

    controls_->setLayout( hlayout);
	layout->addWidget( controls_);

    window_->setLayout( layout);
}

editor_impl::~editor_impl() { window_->deleteLater();}

void editor_impl::run()
{
	python::console_t::Instance().clear();
    undo::stack_t::Instance().clear();

    QString script = edit_->toPlainText();

    try
    {
		boost::python::handle<> ignored(( PyRun_String( script.toStdString().c_str(), Py_file_input,
														ramen::python::interpreter_t::Instance().main_namespace().ptr(),
														ramen::python::interpreter_t::Instance().main_namespace().ptr())));

		ui::user_interface_t::Instance().update();
    }
    catch( boost::python::error_already_set)
    {
		PyErr_Print();
		PyErr_Clear();
    }
}

void editor_impl::show_context_menu( const QPoint& p)
{
}

} // namespace
} // namespace
} // namespace
