/*
 * Last changed at upstream commit 3ff529142f6e2707d57b10eb87ac8d86e9098b88
 * https://github.com/espressif/esp32c3-bt-lib/commit/3ff529142f6e2707d57b10eb87ac8d86e9098b88
 * Upstream date: 2025-06-05 11:04:06 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(4713a69)
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
  if ((((byte)(cVar1 - 1U) < 2) && ((_DAT_60042000 >> 0xf & 1) != 0)) &&
     (uVar2 = (**(code **)(_r_osi_funcs_p + 0x8c))
                        (_DAT_60042004 - _DAT_60042008,0,*(code **)(_r_osi_funcs_p + 0x8c)),
     200 < uVar2)) {
    _DAT_60042000 = _DAT_60042000 | 0x10;
  }
                    /* WARNING: Could not recover jumptable at 0x000102ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

