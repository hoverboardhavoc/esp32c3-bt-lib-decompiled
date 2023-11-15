/*
 * Last changed at upstream commit cecbe387799b41346c0affab41f339306a33e518
 * https://github.com/espressif/esp32c3-bt-lib/commit/cecbe387799b41346c0affab41f339306a33e518
 * Upstream date: 2023-11-15 16:38:32 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2758518)
 * Source: libbtdm_app -> arch_main.o -> rw_pre_main
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rw_pre_main(void)

{
  int iVar1;
  
  btdm_rom_ref_init();
  rw_em_show();
  (**(code **)(_r_plf_funcs_p + 0xb0))(*(code **)(_r_plf_funcs_p + 0xb0));
  (**(code **)(_r_plf_funcs_p + 0xc0))(*(code **)(_r_plf_funcs_p + 0xc0));
  (**(code **)(_r_plf_funcs_p + 0x8c))(*(code **)(_r_plf_funcs_p + 0x8c));
  (**(code **)(_r_plf_funcs_p + 0x50))(*(code **)(_r_plf_funcs_p + 0x50));
  (**(code **)(_r_modules_funcs_p + 0x240))(4,0x800,*(code **)(_r_modules_funcs_p + 0x240));
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(char *)(iVar1 + 0x17) == '\0') {
    if (_r_h4tl_eif_p == 0) {
      if (0 < _g_bt_plf_log_level) {
        ets_printf("H4TL EIF not registered\n");
      }
      (**(code **)(_r_plf_funcs_p + 8))(0,"arch_main.c",0x352,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      (**(code **)(_r_h4tl_eif_p + 0xc))(*(code **)(_r_h4tl_eif_p + 0xc));
    }
  }
  else {
    iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (*(char *)(iVar1 + 0x17) == '\x01') {
      (**(code **)(_r_plf_funcs_p + 0xcc))(*(code **)(_r_plf_funcs_p + 0xcc));
    }
  }
  (**(code **)(_r_plf_funcs_p + 0x94))(*(code **)(_r_plf_funcs_p + 0x94));
                    /* WARNING: Could not recover jumptable at 0x00010c6e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x27c))(0);
  return;
}

