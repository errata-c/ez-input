
if(NOT TARGET glm::glm)
	find_dependency(glm CONFIG)
endif()

if(NOT TARGET ez::bitflags) 
	find_dependency(ez-bitflags CONFIG)
endif()