/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> arch_main.o -> rw_pre_main
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
  r_emi_base_reg_lut_show();
  r_emi_init();
  r_intc_init();
  if (DAT_00013045 != '\0') {
    r_flash_init();
  }
  if (btdm_get_power_state_impl != (code)0x0) {
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
      r_assert_err(0,"arch_main.c",0x4ca);
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

