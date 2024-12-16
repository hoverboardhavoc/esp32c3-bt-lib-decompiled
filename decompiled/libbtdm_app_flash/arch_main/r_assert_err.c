/*
 * Last changed at upstream commit 4c16da1a1a76b439e2cf981d2f915d94df364e58
 * https://github.com/espressif/esp32c3-bt-lib/commit/4c16da1a1a76b439e2cf981d2f915d94df364e58
 * Upstream date: 2024-12-16 11:11:02 +0800
 * Upstream subject: fix(bt): Fixed that the resolvable private address does not change when light sleep is enabled(6bca137)
 * Source: libbtdm_app_flash -> arch_main.o -> r_assert_err
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_assert_err(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  r_rwip_assert(param_1,param_2,0,0,1);
  ebreak();
  btdm_rom_ref_init(uRam00000000);
  rw_em_show();
  r_emi_base_reg_lut_show();
  r_emi_init();
  r_intc_init();
  if (DAT_00012035 != '\0') {
    r_flash_init();
  }
  if (btdm_env_p != '\0') {
    r_nvds_init(4,0x800);
  }
  iVar1 = r_sdk_config_get_opts();
  if (*(char *)(iVar1 + 0x17) == '\0') {
    iVar1 = _r_h4tl_eif_p;
    if (_r_h4tl_eif_p == 0) {
      iVar1 = _g_bt_plf_log_level;
      if (0 < _g_bt_plf_log_level) {
        ets_printf("H4TL EIF not registered\n");
      }
      r_assert_err(0,"arch_main.c",0x389);
    }
    (**(code **)(iVar1 + 0xc))(*(code **)(iVar1 + 0xc));
  }
  else {
    iVar1 = r_sdk_config_get_opts();
    if (*(char *)(iVar1 + 0x17) == '\x01') {
      r_vhci_init();
    }
  }
  r_led_init();
  r_rwip_init(0);
  return;
}

