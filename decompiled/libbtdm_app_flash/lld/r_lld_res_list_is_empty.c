/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_res_list_is_empty
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool r_lld_res_list_is_empty(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = 0;
  do {
    iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
    uVar2 = uVar1 & 0xff;
    if (*(short *)(iVar3 + uVar1 * 0x34) < 0) goto _L428;
    uVar1 = uVar1 + 1;
  } while (uVar1 != 10);
  uVar2 = 10;
_L428:
  return uVar2 == 10;
}

