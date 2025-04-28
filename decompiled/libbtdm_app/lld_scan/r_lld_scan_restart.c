/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar3 = 0xc;
  if (_lld_scan_env != 0) {
    iVar5 = 0;
    while( true ) {
      iVar2 = *(int *)(_lld_scan_env + iVar5 * 4);
      if ((((iVar2 != 0) && (*(char *)(iVar2 + 0x3c) == '\0')) &&
          (iVar3 = (**(code **)(_r_ip_funcs_p + 0x264))(iVar3,*(code **)(_r_ip_funcs_p + 0x264)),
          *(char *)(iVar2 + 0x3e) != '\x01')) &&
         ((uVar4 = *(int *)(iVar2 + 4) - iVar3 & 0xfffffff, uVar4 < 0x8000001 && (0x3c < uVar4)))) {
        (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar2,0,*(code **)(_r_ip_funcs_p + 0x6b8));
        iVar1 = _r_ip_funcs_p;
        *(int *)(iVar2 + 4) = iVar3;
        iVar3 = (**(code **)(iVar1 + 0x6b0))(iVar2,*(code **)(iVar1 + 0x6b0));
      }
      if (iVar5 == 1) break;
      iVar5 = 1;
    }
    iVar3 = 0;
  }
  return iVar3;
}

