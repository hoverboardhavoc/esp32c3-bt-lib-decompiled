/*
 * Last changed at upstream commit 70f95a1b6f8f232018b17c687cc819044501774c
 * https://github.com/espressif/esp32c3-bt-lib/commit/70f95a1b6f8f232018b17c687cc819044501774c
 * Upstream date: 2024-04-02 18:59:02 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5274796)
 * Source: libbtdm_app -> lld_scan.o -> coex_lld_scan_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void coex_lld_scan_stop(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int aiStack_34 [3];
  
  iVar4 = 0;
  while( true ) {
    iVar2 = *(int *)(_lld_scan_env + iVar4 * 4);
    if (iVar2 != 0) {
      if (*(char *)(iVar2 + 0x3c) == '\0') {
        (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar2,0,*(code **)(_r_ip_funcs_p + 0x6b8));
        (**(code **)(_r_ip_funcs_p + 0x718))(0,*(code **)(_r_ip_funcs_p + 0x718));
        aiStack_34[0] = 0;
        iVar3 = coex_schm_ble_scan_stop_interval_num_get
                          (*(undefined2 *)(iVar2 + 0x30),*(undefined2 *)(iVar2 + 0x32),
                           *(undefined4 *)(iVar2 + 4),aiStack_34);
        *(uint *)(iVar2 + 4) =
             ((uint)*(ushort *)(iVar2 + 0x30) * iVar3 + aiStack_34[0]) * 2 + *(int *)(iVar2 + 4) &
             0xffffffe;
        *(uint *)(iVar2 + 0x24) = (uint)*(ushort *)(iVar2 + 0x32) - aiStack_34[0];
        (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar2,*(code **)(_r_ip_funcs_p + 0x6b0));
      }
      else if (*(char *)(iVar2 + 0x3c) == '\x01') {
        bVar1 = *(byte *)(iVar2 + 0x38);
        iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)(iVar2 + (uint)bVar1 * 0x5a + 0x20) = 1;
        _DAT_60031000 = _DAT_60031000 & 0xfeffffff | 0x1000000;
        _LANCHOR2 = 1;
      }
    }
    if (iVar4 != 0) break;
    iVar4 = 1;
  }
  return;
}

