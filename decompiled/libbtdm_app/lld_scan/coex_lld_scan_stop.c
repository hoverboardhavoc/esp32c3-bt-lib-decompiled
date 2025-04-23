/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_scan.o -> coex_lld_scan_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void coex_lld_scan_stop(void)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_24 [2];
  
  iVar5 = 0;
  do {
    iVar3 = *(int *)(_lld_scan_env + iVar5 * 4);
    if (iVar3 != 0) {
      if (*(char *)(iVar3 + 0x3c) == '\0') {
        (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar3,0,*(code **)(_r_ip_funcs_p + 0x6b8));
        (**(code **)(_r_ip_funcs_p + 0x718))(0,*(code **)(_r_ip_funcs_p + 0x718));
        local_24[0] = 0;
        iVar4 = coex_schm_ble_scan_stop_interval_num_get
                          (*(undefined2 *)(iVar3 + 0x30),*(undefined2 *)(iVar3 + 0x32),
                           *(undefined4 *)(iVar3 + 4),local_24);
        *(uint *)(iVar3 + 4) =
             ((uint)*(ushort *)(iVar3 + 0x30) * iVar4 + local_24[0]) * 2 + *(int *)(iVar3 + 4) &
             0xffffffe;
        *(uint *)(iVar3 + 0x24) = (uint)*(ushort *)(iVar3 + 0x32) - local_24[0];
        (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar3,*(code **)(_r_ip_funcs_p + 0x6b0));
      }
      else if (*(char *)(iVar3 + 0x3c) == '\x01') {
        bVar2 = *(byte *)(iVar3 + 0x38);
        iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)((uint)bVar2 * 0x5a + 0x20 + iVar3) = 1;
        _DAT_60031000 = _DAT_60031000 | 0x1000000;
        lld_scan_evt_end_reason = 1;
      }
    }
    bVar1 = iVar5 != 1;
    iVar5 = 1;
  } while (bVar1);
  return;
}

