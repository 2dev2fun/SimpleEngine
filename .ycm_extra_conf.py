import os
import ycm_core

def Settings(**kwargs):
    return { 'flags': [
        '-x', 'c++',
        '-std=c++17',
        '-Wall',
        '-Wextra'
        '-Werror',
        '-isystem', './source',
        '-isystem', './library/glad/include',
        '-isystem', './modules/glfw/include',
    ] }
