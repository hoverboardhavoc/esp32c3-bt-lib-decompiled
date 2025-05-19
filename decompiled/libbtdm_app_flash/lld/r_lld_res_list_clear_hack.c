/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_res_list_clear_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_res_list_clear_hack(void)

{
  ushort uVar1;
  int iVar2;
  undefined1 *__s;
  int iVar3;
  
  __s = &lld_rpa_res_list;
  iVar2 = 0;
  do {
    iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
    uVar1 = *(ushort *)(iVar3 + iVar2);
    iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
    *(ushort *)(iVar3 + iVar2) = uVar1 & 0x7fff;
    iVar2 = iVar2 + 0x34;
    memset(__s,0,0xd);
    __s = __s + 0xd;
  } while (iVar2 != 0x208);
  return;
}

