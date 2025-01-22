

set(UI_LITE_DIR ${CMAKE_CURRENT_LIST_DIR}/../../../foundation/arkui/ui_lite)

set(SRCS 
${UI_LITE_DIR}/frameworks/animator/animator.cpp
${UI_LITE_DIR}/frameworks/animator/animator_manager.cpp
${UI_LITE_DIR}/frameworks/animator/easing_equation.cpp
${UI_LITE_DIR}/frameworks/animator/interpolation.cpp
${UI_LITE_DIR}/frameworks/common/graphic_startup.cpp
${UI_LITE_DIR}/frameworks/common/image.cpp
${UI_LITE_DIR}/frameworks/common/image_decode_ability.cpp
${UI_LITE_DIR}/frameworks/common/input_device_manager.cpp
${UI_LITE_DIR}/frameworks/common/screen.cpp
${UI_LITE_DIR}/frameworks/common/spannable_string.cpp
${UI_LITE_DIR}/frameworks/common/task.cpp
${UI_LITE_DIR}/frameworks/common/text.cpp
${UI_LITE_DIR}/frameworks/common/typed_text.cpp
${UI_LITE_DIR}/frameworks/components/root_view.cpp
${UI_LITE_DIR}/frameworks/components/text_adapter.cpp
${UI_LITE_DIR}/frameworks/components/ui_abstract_clock.cpp
${UI_LITE_DIR}/frameworks/components/ui_abstract_progress.cpp
${UI_LITE_DIR}/frameworks/components/ui_abstract_scroll.cpp
${UI_LITE_DIR}/frameworks/components/ui_abstract_scroll_bar.cpp
${UI_LITE_DIR}/frameworks/components/ui_analog_clock.cpp
${UI_LITE_DIR}/frameworks/components/ui_arc_label.cpp
${UI_LITE_DIR}/frameworks/components/ui_arc_scroll_bar.cpp
${UI_LITE_DIR}/frameworks/components/ui_axis.cpp
${UI_LITE_DIR}/frameworks/components/ui_box_progress.cpp
${UI_LITE_DIR}/frameworks/components/ui_box_scroll_bar.cpp
${UI_LITE_DIR}/frameworks/components/ui_button.cpp
${UI_LITE_DIR}/frameworks/components/ui_canvas.cpp
${UI_LITE_DIR}/frameworks/components/ui_chart.cpp
${UI_LITE_DIR}/frameworks/components/ui_checkbox.cpp
${UI_LITE_DIR}/frameworks/components/ui_circle_progress.cpp
${UI_LITE_DIR}/frameworks/components/ui_dialog.cpp
${UI_LITE_DIR}/frameworks/components/ui_digital_clock.cpp
${UI_LITE_DIR}/frameworks/components/ui_edit_text.cpp
${UI_LITE_DIR}/frameworks/components/ui_extend_image_view.cpp
${UI_LITE_DIR}/frameworks/components/ui_image_animator.cpp
${UI_LITE_DIR}/frameworks/components/ui_image_view.cpp
${UI_LITE_DIR}/frameworks/components/ui_label.cpp
${UI_LITE_DIR}/frameworks/components/ui_label_button.cpp
${UI_LITE_DIR}/frameworks/components/ui_list.cpp
${UI_LITE_DIR}/frameworks/components/ui_picker.cpp
${UI_LITE_DIR}/frameworks/components/ui_qrcode.cpp
${UI_LITE_DIR}/frameworks/components/ui_radio_button.cpp
${UI_LITE_DIR}/frameworks/components/ui_repeat_button.cpp
${UI_LITE_DIR}/frameworks/components/ui_scroll_view.cpp
${UI_LITE_DIR}/frameworks/components/ui_slider.cpp
${UI_LITE_DIR}/frameworks/components/ui_surface_view.cpp
${UI_LITE_DIR}/frameworks/components/ui_swipe_view.cpp
${UI_LITE_DIR}/frameworks/components/ui_texture_mapper.cpp
${UI_LITE_DIR}/frameworks/components/ui_time_picker.cpp
${UI_LITE_DIR}/frameworks/components/ui_toggle_button.cpp
${UI_LITE_DIR}/frameworks/components/ui_tree_manager.cpp
${UI_LITE_DIR}/frameworks/components/ui_view.cpp
${UI_LITE_DIR}/frameworks/components/ui_view_group.cpp
${UI_LITE_DIR}/frameworks/core/input_method_manager.cpp
${UI_LITE_DIR}/frameworks/core/render_manager.cpp
${UI_LITE_DIR}/frameworks/core/task_manager.cpp
${UI_LITE_DIR}/frameworks/default_resource/check_box_res.cpp
${UI_LITE_DIR}/frameworks/dfx/event_injector.cpp
${UI_LITE_DIR}/frameworks/dfx/key_event_injector.cpp
${UI_LITE_DIR}/frameworks/dfx/performance_task.cpp
${UI_LITE_DIR}/frameworks/dfx/point_event_injector.cpp
${UI_LITE_DIR}/frameworks/dfx/ui_dump_dom_tree.cpp
${UI_LITE_DIR}/frameworks/dfx/ui_screenshot.cpp
${UI_LITE_DIR}/frameworks/dfx/ui_view_bounds.cpp
${UI_LITE_DIR}/frameworks/dock/focus_manager.cpp
${UI_LITE_DIR}/frameworks/dock/input_device.cpp
${UI_LITE_DIR}/frameworks/dock/key_input_device.cpp
${UI_LITE_DIR}/frameworks/dock/ohos/ohos_input_device.cpp
${UI_LITE_DIR}/frameworks/dock/pointer_input_device.cpp
${UI_LITE_DIR}/frameworks/dock/rotate_input_device.cpp
${UI_LITE_DIR}/frameworks/dock/screen_device_proxy.cpp
${UI_LITE_DIR}/frameworks/dock/vibrator_manager.cpp
${UI_LITE_DIR}/frameworks/dock/virtual_input_device.cpp
${UI_LITE_DIR}/frameworks/draw/clip_utils.cpp
${UI_LITE_DIR}/frameworks/draw/draw_arc.cpp
${UI_LITE_DIR}/frameworks/draw/draw_canvas.cpp
${UI_LITE_DIR}/frameworks/draw/draw_curve.cpp
${UI_LITE_DIR}/frameworks/draw/draw_image.cpp
${UI_LITE_DIR}/frameworks/draw/draw_label.cpp
${UI_LITE_DIR}/frameworks/draw/draw_line.cpp
${UI_LITE_DIR}/frameworks/draw/draw_rect.cpp
${UI_LITE_DIR}/frameworks/draw/draw_triangle.cpp
${UI_LITE_DIR}/frameworks/draw/draw_utils.cpp
${UI_LITE_DIR}/frameworks/engines/gfx/gfx_engine_manager.cpp
${UI_LITE_DIR}/frameworks/engines/gfx/hi3516/hi3516_engine.cpp
${UI_LITE_DIR}/frameworks/engines/gfx/soft_engine.cpp
${UI_LITE_DIR}/frameworks/events/event.cpp
${UI_LITE_DIR}/frameworks/font/base_font.cpp
${UI_LITE_DIR}/frameworks/font/font_ram_allocator.cpp
${UI_LITE_DIR}/frameworks/font/glyphs_cache.cpp
${UI_LITE_DIR}/frameworks/font/glyphs_file.cpp
${UI_LITE_DIR}/frameworks/font/glyphs_manager.cpp
${UI_LITE_DIR}/frameworks/font/ui_font.cpp
${UI_LITE_DIR}/frameworks/font/ui_font_adaptor.cpp
${UI_LITE_DIR}/frameworks/font/ui_font_allocator.cpp
${UI_LITE_DIR}/frameworks/font/ui_font_bitmap.cpp
${UI_LITE_DIR}/frameworks/font/ui_font_builder.cpp
${UI_LITE_DIR}/frameworks/font/ui_font_cache.cpp
${UI_LITE_DIR}/frameworks/font/ui_font_cache_manager.cpp
${UI_LITE_DIR}/frameworks/font/ui_font_vector.cpp
${UI_LITE_DIR}/frameworks/font/ui_line_break.cpp
${UI_LITE_DIR}/frameworks/font/ui_multi_font_manager.cpp
${UI_LITE_DIR}/frameworks/font/ui_text_shaping.cpp
${UI_LITE_DIR}/frameworks/imgdecode/cache_manager.cpp
${UI_LITE_DIR}/frameworks/imgdecode/file_img_decoder.cpp
${UI_LITE_DIR}/frameworks/imgdecode/image_load.cpp
${UI_LITE_DIR}/frameworks/layout/flex_layout.cpp
${UI_LITE_DIR}/frameworks/layout/grid_layout.cpp
${UI_LITE_DIR}/frameworks/layout/list_layout.cpp
${UI_LITE_DIR}/frameworks/render/render_base.cpp
${UI_LITE_DIR}/frameworks/render/render_pixfmt_rgba_blend.cpp
${UI_LITE_DIR}/frameworks/render/render_scanline.cpp
${UI_LITE_DIR}/frameworks/themes/theme.cpp
${UI_LITE_DIR}/frameworks/themes/theme_manager.cpp
${UI_LITE_DIR}/frameworks/window/window.cpp
${UI_LITE_DIR}/frameworks/window/window_impl.cpp
${UI_LITE_DIR}/frameworks/themes/theme.cpp
${UI_LITE_DIR}/frameworks/themes/theme_manager.cpp
${UI_LITE_DIR}/frameworks/dfx/ui_dump_dom_tree.cpp

${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/diagram/common/paint.cpp
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/diagram/depiction/depict_curve.cpp
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/diagram/rasterizer/rasterizer_cells_antialias.cpp
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/diagram/rasterizer/rasterizer_scanline_antialias.cpp
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/diagram/rasterizer/rasterizer_scanline_clip.cpp
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/graphic_timer.cpp
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/trans_affine.cpp
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/diagram/vertexgenerate/vertex_generate_dash.cpp
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/diagram/vertexgenerate/vertex_generate_stroke.cpp
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/diagram/vertexprimitive/geometry_arc.cpp
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/diagram/vertexprimitive/geometry_bezier_arc.cpp
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/diagram/vertexprimitive/geometry_curves.cpp
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/diagram/vertexprimitive/geometry_shorten_path.cpp

${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/color.cpp
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/geometry2d.cpp
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/graphic_math.cpp
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/graphic_performance.cpp
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/hal_tick.cpp
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/mem_api.cpp
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/style.cpp
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/sys_info.cpp
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/transform.cpp
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/frameworks/version.cpp
)

list(REMOVE_ITEM SRCS 
${UI_LITE_DIR}/frameworks/components/ui_surface_view.cpp
# ${UI_LITE_DIR}/frameworks/dfx/ui_dump_dom_tree.cpp
${UI_LITE_DIR}/frameworks/dfx/ui_screenshot.cpp
${UI_LITE_DIR}/frameworks/engines/gfx/hi3516/hi3516_engine.cpp
${UI_LITE_DIR}/frameworks/window/window.cpp
${UI_LITE_DIR}/frameworks/window/window_impl.cpp
)

set(INCLUDE_DIRS 
${UI_LITE_DIR}/frameworks
${UI_LITE_DIR}/interfaces/innerkits
${UI_LITE_DIR}/interfaces/innerkits/common
${UI_LITE_DIR}/interfaces/kits
${UI_LITE_DIR}/interfaces/kits/animator
${UI_LITE_DIR}/interfaces/kits/components
${UI_LITE_DIR}/interfaces/kits/common
${UI_LITE_DIR}/interfaces/kits/layout
${UI_LITE_DIR}/interfaces/kits/font
${UI_LITE_DIR}/interfaces/kits/dfx

${UI_LITE_DIR}/../../graphic/graphic_utils_lite/interfaces/innerkits
${UI_LITE_DIR}/../../graphic/graphic_utils_lite/interfaces/kits
${UI_LITE_DIR}/../../window/window_manager_lite/interfaces/innerkits
)

# For test
set(TEST_SRCS 
${TARGET_DIR}/test/framework/common/ui_text_language.cpp
${TARGET_DIR}/test/framework/src/test_case_list_adapter.cpp
${TARGET_DIR}/test/framework/src/ui_test_group.cpp
${TARGET_DIR}/test/framework/src/test_ability.cpp
${TARGET_DIR}/test/framework/src/ui_test_app.cpp
${TARGET_DIR}/test/uitest/test_animator/ui_test_animator.cpp
${TARGET_DIR}/test/uitest/test_anti_aliasing/ui_test_anti_aliasing.cpp
${TARGET_DIR}/test/uitest/test_arc_label/ui_test_arc_label.cpp
${TARGET_DIR}/test/uitest/test_border_margin_padding/ui_test_border_margin_padding.cpp
${TARGET_DIR}/test/uitest/test_button/ui_test_button.cpp
${TARGET_DIR}/test/uitest/test_canvas/ui_test_canvas.cpp
${TARGET_DIR}/test/uitest/test_chart/ui_test_chart_pillar.cpp
${TARGET_DIR}/test/uitest/test_chart/ui_test_chart_polyline.cpp
${TARGET_DIR}/test/uitest/test_clip/ui_test_clip.cpp
${TARGET_DIR}/test/uitest/test_dialog/ui_test_dialog.cpp
${TARGET_DIR}/test/uitest/test_digital_clock/ui_test_digital_clock.cpp
${TARGET_DIR}/test/uitest/test_draw_line/ui_test_draw_line.cpp
${TARGET_DIR}/test/uitest/test_draw_rect/ui_test_draw_rect.cpp
${TARGET_DIR}/test/uitest/test_edit_text/ui_test_edit_text.cpp
${TARGET_DIR}/test/uitest/test_edit_text/custom_input_method.cpp
${TARGET_DIR}/test/uitest/test_event_injector/ui_test_event_injector.cpp
${TARGET_DIR}/test/uitest/test_focus_manager/ui_test_focus_manager.cpp
${TARGET_DIR}/test/uitest/test_font/ui_test_font.cpp
${TARGET_DIR}/test/uitest/test_image/ui_test_image.cpp
${TARGET_DIR}/test/uitest/test_image_animator/ui_test_image_animator.cpp
${TARGET_DIR}/test/uitest/test_input_event/ui_test_input_event.cpp
${TARGET_DIR}/test/uitest/test_label/ui_test_label.cpp
${TARGET_DIR}/test/uitest/test_layout/ui_test_advanced_layout.cpp
${TARGET_DIR}/test/uitest/test_layout/ui_test_basic_layout.cpp
${TARGET_DIR}/test/uitest/test_opacity/ui_test_opacity.cpp
${TARGET_DIR}/test/uitest/test_picker/ui_test_ui_picker.cpp
${TARGET_DIR}/test/uitest/test_progress_bar/ui_test_box_progress.cpp
${TARGET_DIR}/test/uitest/test_progress_bar/ui_test_circle_progress.cpp
${TARGET_DIR}/test/uitest/test_qrcode/ui_test_qrcode.cpp
${TARGET_DIR}/test/uitest/test_render/ui_test_render.cpp
${TARGET_DIR}/test/uitest/test_rotate_input/ui_test_rotate_input.cpp
${TARGET_DIR}/test/uitest/test_scroll_bar/ui_test_scroll_bar.cpp
${TARGET_DIR}/test/uitest/test_slider/ui_test_slider.cpp
${TARGET_DIR}/test/uitest/test_spannable_string/ui_test_spannnable_string.cpp
${TARGET_DIR}/test/uitest/test_texture_mapper/ui_test_texture_mapper.cpp
${TARGET_DIR}/test/uitest/test_transform/ui_test_transform.cpp
${TARGET_DIR}/test/uitest/test_ui_analog_clock/ui_test_analog_clock.cpp
${TARGET_DIR}/test/uitest/test_ui_dump_dom_tree/ui_test_dump_dom.cpp
${TARGET_DIR}/test/uitest/test_ui_list/ui_test_ui_list.cpp
${TARGET_DIR}/test/uitest/test_ui_list_view/ui_test_list_layout.cpp
${TARGET_DIR}/test/uitest/test_ui_scroll_view/ui_test_ui_scroll_view.cpp
${TARGET_DIR}/test/uitest/test_ui_swipe_view/ui_test_ui_swipe_view.cpp
${TARGET_DIR}/test/uitest/test_vector_font/ui_test_vector_font.cpp
${TARGET_DIR}/test/uitest/test_view_bitmap/ui_test_view_bitmap.cpp
${TARGET_DIR}/test/uitest/test_view_bounds/ui_test_view_bounds.cpp
${TARGET_DIR}/test/uitest/test_view_group/ui_test_view_group.cpp
${TARGET_DIR}/test/uitest/test_view_percent/ui_test_view_percent.cpp
${TARGET_DIR}/test/uitest/test_view_zindex/ui_test_view_zindex.cpp
${TARGET_DIR}/test/uitest/test_view_scale_rotate/ui_test_view_scale_rotate.cpp
)

set(TEST_INCLUDE_DIRS 
${TARGET_DIR}/test/framework
${TARGET_DIR}/test/framework/include
${TARGET_DIR}/test/uitest
)


idf_component_register(
    SRCS ${SRCS} ${TEST_SRCS}
    INCLUDE_DIRS ${INCLUDE_DIRS} ${TEST_INCLUDE_DIRS}
    REQUIRES bounds_checking_function qrcodegen freetype icu libjpeg-turbo json porting
)

target_compile_options(${COMPONENT_LIB} PRIVATE -fno-exceptions)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-missing-field-initializers)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-deprecated-copy)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-deprecated-enum-enum-conversion)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-deprecated-enum-float-conversion)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-array-bounds)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-unknown-pragmas)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-error=uninitialized)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-format)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-write-strings)


target_compile_definitions(${COMPONENT_LIB} PUBLIC 
__LITEOS_M__

ENABLE_FPS_SUPPORT=1
ENABLE_GRAPHIC_LOG=1
GRAPHIC_ENABLE_ELLIPSE_FLAG=1
GRAPHIC_ENABLE_BEZIER_ARC_FLAG=1
GRAPHIC_ENABLE_LINECAP_FLAG=1
GRAPHIC_ENABLE_LINEJOIN_FLAG=1
GRAPHIC_ENABLE_ARC_FLAG=1
GRAPHIC_ENABLE_ROUNDEDRECT_FLAG=1
GRAPHIC_ENABLE_GRADIENT_FILL_FLAG=1
GRAPHIC_ENABLE_SHADOW_EFFECT_FLAG=1
GRAPHIC_ENABLE_DRAW_IMAGE_FLAG=1
GRAPHIC_ENABLE_DRAW_TEXT_FLAG=1
GRAPHIC_ENABLE_DASH_GENERATE_FLAG=1
GRAPHIC_ENABLE_BLUR_EFFECT_FLAG=1
GRAPHIC_ENABLE_PATTERN_FILL_FLAG=1

ENABLE_DEBUG=1
ENABLE_SPANNABLE_STRING=1
ENABLE_CANVAS_EXTEND=1
ENABLE_MULTI_FONT=1
ENABLE_SHAPING=0
ENABLE_GIF=0
ENABLE_PNG=1
ENABLE_JPEG=1
ENABLE_ICU=1
ENABLE_VECTOR_FONT=1
ENABEL_UI_AUTO_TEST=0

DEFAULT_ANIMATION=1

)
