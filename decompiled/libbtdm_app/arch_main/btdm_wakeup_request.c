/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
 * Source: libbtdm_app -> arch_main.o -> btdm_wakeup_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_wakeup_request(void)

{
  char cVar1;
  uint uVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  cVar1 = btdm_get_power_state_impl();
  if ((((byte)(cVar1 - 1U) < 2) && ((int)(_DAT_60042000 << 0x10) < 0)) &&
     (uVar2 = (**(code **)(_r_osi_funcs_p + 0x8c))
                        (_DAT_60042004 - _DAT_60042008,0,*(code **)(_r_osi_funcs_p + 0x8c)),
     200 < uVar2)) {
    _DAT_60042000 = _DAT_60042000 | 0x10;
  }
                    /* WARNING: Could not recover jumptable at 0x000101ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

