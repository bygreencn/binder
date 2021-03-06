// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// (c) Copyright Rosetta Commons Member Institutions.
// (c) This file is part of the Rosetta software suite and is made available under license.
// (c) The Rosetta software is developed by the contributing members of the Rosetta Commons.
// (c) For more information, see http://www.rosettacommons.org. Questions about this can be
// (c) addressed to University of Washington CoMotion, email: license@uw.edu.

/// @file   binder/test/T20.template.hpp
/// @brief  Binder self-test file. Bindings of temlate classes and functions functionality.
/// @author Sergey Lyskov

#ifndef _INCLUDED_T20_template_hpp_
#define _INCLUDED_T20_template_hpp_

template <typename T>
void foo() {}

template void foo<int>();
template void foo<double>();


template <typename T>
class A
{
public:
	T t_value;
	T *t_pointer;

	void foo(T&) {}
};

void fi_instantiated_by_use_in_function(A<int> ) {}
void fi(A<int> &) {}
void fi(A<int> *) {}

void ff_instantiated_by_use_in_function_not_binded(A<float> &) {}  // accessing class by reference will not trigger class instantiation
void fd_instantiated_by_use_in_function_not_binded(A<double> *) {} // accessing class by pointer will not trigger class instantiation

#endif // _INCLUDED_T20_template_hpp_
