# TestDll
Analyzing Pros and Cons of Prefering to define templates in headers vs single translation units

# pch.h

Uncommon (slightly frowned upon) forward declaration of std components. Specifically in order to enable referencing of std::map and std::vector without instantiating the templates in the header. The concept is using the [Pimpl](https://en.cppreference.com/w/cpp/language/pimpl) idiom on larger standard library utilities.

# shared_header.h

Two template functions demonstrating in header definition, and single TU definition (backed by template instantiation, extern template used but not particularly important).

# source1.cpp

Instantiation of template defined in header that will generate within the source1.obj

# source2.cpp

Usage of template instantiated in shared_header.cpp, which should not include instantiation in source2.obj

# source3.cpp

Example of situations where preinstantiated templates become difficult, anonymous namespaces prevent instantiating template in shared_header.cpp. Exposing the LocalValue class in the source3.h header could come at the cost of loss of value semantics among other reasons such as requiring significant refactoring if one class required other dependencies such as further template instantiations or inheritance schemes. In header template definitions (as in the source1.cpp usage case) remain idiomatic.

# source4.cpp and source5.cpp

An argument that code leveraging functionality delivered by in header definitions already were instantiating the required symbols anyway, the refactoring does not introduce more instantiations (std::map::find is already in use for example, the template function did not add more instantiations just summarized logic). So enforcing a single TU definition is attempting to optimize a different aspect of compilation (coming at the cost of additional lines of code being introduced with extra context required to make use of "library"-like functions.

# Conclusion (opinionated)

Instantiating templates by using single TUs is cumbersome but a valid way of reducing instantiations overall. However, it doesn't work in all cases, nor is neccessarily a good default (it just has benefits in some situations and cons in others). A more practical approach when enforcing this optimization would be to create tooling to assess anomalistic compile times on templates and address concerns through a more evidential process. E.g, /d2cgsummary can yield info on  lengthy compile times in MSVC. Alternatively, assess all output .obj's and identify symbols S that are produced X times, benchmark time T taken to instantiate (or define) S. And consider if for S, X*T being reduced to T is achievable and useful. Using unorthodox C++ practices requires training, discussion, maintenance, troubleshooting is a negative time factor.

Also consider C++20's modules: which though they do not solve template instantiation costs, may have a positive effect on number of duplicate instantiations throughout a build.
