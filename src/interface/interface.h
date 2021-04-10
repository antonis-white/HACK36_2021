#pragma once
#include "comment.h"
#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <queue>
#include <memory>

void new_location(user_ptr& user);

void location_changer(user_ptr& user);

void aller_button_click(user_ptr& user);
 
bool tick(user_ptr& user);