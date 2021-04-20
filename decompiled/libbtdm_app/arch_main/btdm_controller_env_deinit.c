/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_env_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_controller_env_deinit(void)

{
  (**(code **)(_r_ip_funcs_p + 0x240))(*(code **)(_r_ip_funcs_p + 0x240));
  (**(code **)(_r_ip_funcs_p + 0x4cc))(*(code **)(_r_ip_funcs_p + 0x4cc));
  (**(code **)(_r_ip_funcs_p + 0xe0))(*(code **)(_r_ip_funcs_p + 0xe0));
  (**(code **)(_r_plf_funcs_p + 0x48))(*(code **)(_r_plf_funcs_p + 0x48));
  (**(code **)(_r_ip_funcs_p + 0x40))(*(code **)(_r_ip_funcs_p + 0x40));
  if (*_btdm_env_p != 0) {
    (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
  }
  if (_btdm_env_p[2] != 0) {
    (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
  }
  if (_btdm_env_p[4] != 0) {
    (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
  }
  if (_btdm_env_p[6] != 0) {
    (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
  }
  if (_btdm_env_p[9] != 0) {
    (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
    _btdm_env_p[9] = 0;
  }
  if (_btdm_env_p != (int *)0x0) {
    (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
    _btdm_env_p = (int *)0x0;
  }
  return;
}

