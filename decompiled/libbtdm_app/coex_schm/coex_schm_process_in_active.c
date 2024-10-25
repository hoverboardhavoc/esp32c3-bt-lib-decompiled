/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> coex_schm.o -> coex_schm_process_in_active
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void coex_schm_process_in_active(void)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  DAT_000101df = 0;
  pbVar2 = (byte *)(**(code **)(_r_osi_funcs_p + 200))(*(code **)(_r_osi_funcs_p + 200));
  if (pbVar2 != (byte *)0x0) {
    iVar3 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
    bVar1 = *pbVar2;
    iVar4 = (**(code **)(_r_osi_funcs_p + 0xc4))(*(code **)(_r_osi_funcs_p + 0xc4));
    iVar5 = (**(code **)(_r_osi_funcs_p + 0xc0))(*(code **)(_r_osi_funcs_p + 0xc0));
    DAT_000101e0 = (((uint)bVar1 * iVar5 * iVar4) / 0x271) * 2 + iVar3 & 0xfffffff;
    if (3 < _g_bt_plf_log_level) {
      ets_printf("SCHM PROC %02x %02x, %p\n",pbVar2[3],pbVar2[2],pbVar2);
    }
    if ((pbVar2[2] & 0x20) != 0) {
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
      if (*(char *)(iVar3 + 0x23) != '\0') {
        coex_schm_ble_scan_stop();
        return;
      }
    }
  }
  return;
}

