/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> arch_main.o -> btdm_ble_power_down_dma_copy
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_ble_power_down_dma_copy(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    (**(code **)(_r_osi_funcs_p + 200))(*(code **)(_r_osi_funcs_p + 200));
    ble_deepsleep_reset_lc_bb_reg();
    ble_deepsleep_recover_hw_reg();
    (**(code **)(_r_osi_funcs_p + 0xcc))
              (0x60031000,_LANCHOR1,0xe1,0,*(code **)(_r_osi_funcs_p + 0xcc));
    (**(code **)(_r_osi_funcs_p + 0xcc))
              (0x60011000,_LANCHOR2,0x38,0,*(code **)(_r_osi_funcs_p + 0xcc));
    _DAT_60026018 = _DAT_60026018 & 0xfffffdf7;
    return;
  }
  (**(code **)(_r_osi_funcs_p + 0xcc))
            (0x60031000,_LANCHOR1,0xe1,1,*(code **)(_r_osi_funcs_p + 0xcc));
  (**(code **)(_r_osi_funcs_p + 0xcc))
            (0x60011000,_LANCHOR2,0x38,1,*(code **)(_r_osi_funcs_p + 0xcc));
  do {
    iVar1 = btdm_sleep_clock_sync();
  } while (iVar1 == 0);
                    /* WARNING: Could not recover jumptable at 0x00011278. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0xc4))();
  return;
}

