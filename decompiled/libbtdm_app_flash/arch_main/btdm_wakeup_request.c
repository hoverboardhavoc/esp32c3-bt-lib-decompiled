/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_wakeup_request
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
                    /* WARNING: Could not recover jumptable at 0x00010236. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

