/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> rwip.o -> r_rwip_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_reset(void)

{
  int iVar1;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  r_vshci_init(rwip_rst_state);
  r_ke_flush();
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x20) != '\0') {
    r_ecc_init(rwip_rst_state);
  }
  r_misc_init(rwip_rst_state);
  r_hci_init(rwip_rst_state);
  if (*(code **)(_r_hli_funcs_p + 8) != (code *)0x0) {
    (**(code **)(_r_hli_funcs_p + 8))(rwip_rst_state);
  }
  r_rwble_init(rwip_rst_state);
  bb_int_init(rwip_rst_state);
  r_rw_crypto_aes_init(rwip_rst_state);
  r_sch_arb_init(rwip_rst_state);
  r_sch_prog_init(rwip_rst_state);
  r_sch_plan_init(rwip_rst_state);
  r_sch_alarm_init(rwip_rst_state);
  r_sch_slice_init(rwip_rst_state);
  r_rwip_driver_init(rwip_rst_state);
  r_rwip_wlcoex_set_part_0();
  if (rwip_rst_state == '\x02') {
    (*_rwip_rf)(_rwip_rf);
  }
  rwip_rst_state = 2;
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  _btdm_pwr_state = 0;
                    /* WARNING: Could not recover jumptable at 0x00010320. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x38))(g_waking_sleeping_sem,*(code **)(_r_osi_funcs_p + 0x38));
  return;
}

