/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_debug_snap.o -> snap_dump_txdesc.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void snap_dump_txdesc_part_0(int param_1,uint param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 9;
  if (param_2 < 10) {
    uVar4 = param_2 & 0xff;
  }
  ets_printf(&__c_30);
  param_1 = param_1 * 0x7e;
  uVar5 = 0;
  do {
    iVar3 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar1 = *(undefined2 *)(iVar3 + param_1);
    iVar3 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar2 = *(undefined2 *)(iVar3 + 2 + param_1);
    iVar3 = r_emi_get_mem_addr_by_offset(0x1400);
    ets_printf(__c_29,uVar5,uVar1,uVar2,*(undefined2 *)(iVar3 + 4 + param_1));
    uVar5 = uVar5 + 1;
    param_1 = param_1 + 0xe;
  } while ((uVar5 & 0xff) < uVar4);
  ets_printf(&__c_28);
  return;
}

