/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_restart
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
  uint uVar3;
  int iVar4;
  
  iVar2 = 0xc;
  if (_lld_scan_env != 0) {
    iVar4 = 0;
    while( true ) {
      iVar1 = *(int *)(_lld_scan_env + iVar4 * 4);
      if ((((iVar1 != 0) && (*(char *)(iVar1 + 0x3c) == '\0')) &&
          (iVar2 = r_lld_read_clock(iVar2), *(char *)(iVar1 + 0x3e) != '\x01')) &&
         ((uVar3 = *(int *)(iVar1 + 4) - iVar2 & 0xfffffff, uVar3 < 0x8000001 && (0x3c < uVar3)))) {
        r_sch_arb_remove(iVar1,0);
        *(int *)(iVar1 + 4) = iVar2;
        iVar2 = r_sch_arb_insert(iVar1);
      }
      if (iVar4 == 1) break;
      iVar4 = 1;
    }
    iVar2 = 0;
  }
  return iVar2;
}

