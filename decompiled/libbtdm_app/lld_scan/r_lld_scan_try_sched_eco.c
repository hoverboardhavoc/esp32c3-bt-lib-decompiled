/*
 * Last changed at upstream commit 70f95a1b6f8f232018b17c687cc819044501774c
 * https://github.com/espressif/esp32c3-bt-lib/commit/70f95a1b6f8f232018b17c687cc819044501774c
 * Upstream date: 2024-04-02 18:59:02 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5274796)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_try_sched_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_try_sched_eco(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (_lld_scan_env != 0) {
    iVar3 = *(int *)(_lld_scan_env + param_1 * 4);
    if (iVar3 != 0) {
      uVar2 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
      if ((*(byte *)(_lld_scan_env + 0xc) & 3) == 3) {
        lld_scan_sched_optimize_part_0(iVar3,uVar2,param_3);
      }
    }
  }
  uVar1 = _coex_schm_ble_scan_stop_interval_num_get;
  _coex_schm_ble_scan_stop_interval_num_get = 0x9c4;
  r_lld_scan_try_sched(param_1,param_2,param_3);
  _coex_schm_ble_scan_stop_interval_num_get = uVar1;
  if (_lld_scan_env != 0) {
    iVar3 = *(int *)(_lld_scan_env + param_1 * 4);
    if ((iVar3 != 0) && (*(uint *)(iVar3 + 0x24) == (uint)*(ushort *)(iVar3 + 0x32))) {
      (&_LANCHOR0)[param_1] = *(undefined4 *)(iVar3 + 4);
    }
  }
  return;
}

