/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  r_vshci_init(_LANCHOR0);
  r_ke_flush();
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x20) != '\0') {
    r_ecc_init(_LANCHOR0);
  }
  r_misc_init(_LANCHOR0);
  r_hci_init(_LANCHOR0);
  if (*(code **)(_r_hli_funcs_p + 8) != (code *)0x0) {
    (**(code **)(_r_hli_funcs_p + 8))(_LANCHOR0);
  }
  r_rwble_init(_LANCHOR0);
  bb_int_init(_LANCHOR0);
  r_rw_crypto_aes_init(_LANCHOR0);
  r_sch_arb_init(_LANCHOR0);
  r_sch_prog_init(_LANCHOR0);
  r_sch_plan_init(_LANCHOR0);
  r_sch_alarm_init(_LANCHOR0);
  r_sch_slice_init(_LANCHOR0);
  r_rwip_driver_init(_LANCHOR0);
  r_rwip_wlcoex_set_part_0();
  if (_LANCHOR0 == '\x02') {
    (*_rwip_rf)(_rwip_rf);
  }
  _LANCHOR0 = 2;
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  _btdm_pwr_state = 0;
                    /* WARNING: Could not recover jumptable at 0x0001032e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x38))(g_waking_sleeping_sem);
  return;
}

