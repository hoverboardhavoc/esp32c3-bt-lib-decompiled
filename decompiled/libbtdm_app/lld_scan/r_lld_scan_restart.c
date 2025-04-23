/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_restart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_lld_scan_restart(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0xc;
  if (_lld_scan_env != 0) {
    iVar5 = 0;
    do {
      iVar3 = *(int *)(_lld_scan_env + iVar5 * 4);
      if ((((iVar3 != 0) && (*(char *)(iVar3 + 0x3c) == '\0')) &&
          (iVar4 = (**(code **)(_r_ip_funcs_p + 0x264))(iVar4,*(code **)(_r_ip_funcs_p + 0x264)),
          *(char *)(iVar3 + 0x3e) != '\x01')) &&
         ((*(int *)(iVar3 + 4) - iVar4 & 0xfffffffU) - 0x3d < 0x7ffffc4)) {
        (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar3,0,*(code **)(_r_ip_funcs_p + 0x6b8));
        iVar2 = _r_ip_funcs_p;
        *(int *)(iVar3 + 4) = iVar4;
        iVar4 = (**(code **)(iVar2 + 0x6b0))(iVar3,*(code **)(iVar2 + 0x6b0));
      }
      bVar1 = iVar5 != 1;
      iVar5 = 1;
    } while (bVar1);
    iVar4 = 0;
  }
  return iVar4;
}

