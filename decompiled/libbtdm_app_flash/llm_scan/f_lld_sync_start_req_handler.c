/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_scan.o -> f_lld_sync_start_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_lld_sync_start_req_handler(byte *param_1)

{
  char cVar1;
  uint uVar2;
  void *__src;
  int iVar3;
  int iVar4;
  byte bVar5;
  int *piVar6;
  int iVar7;
  undefined1 auStack_38 [8];
  byte *pbStack_30;
  undefined4 uStack_2c;
  undefined2 uStack_28;
  byte bStack_26;
  byte bStack_25;
  undefined2 uStack_24;
  undefined2 uStack_22;
  
  iVar7 = (uint)*param_1 * 0x44;
  cVar1 = *(char *)(*(int *)(_p_llm_env + 8) + iVar7 + 0x40);
  if (cVar1 == '\x0e') {
    uVar2 = (uint)*(ushort *)(param_1 + 0x20);
    if (uVar2 == 0) {
      memcpy(auStack_38,param_1 + 0x23,6);
      bVar5 = param_1[0x22];
    }
    else {
      __src = (void *)r_emi_get_mem_addr_by_offset(uVar2 + 0x18 & 0xffff);
      memcpy(auStack_38,__src,6);
      iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
      bVar5 = (byte)*(undefined2 *)(((uVar2 - 0xc60) / 0x34 & 0xff) * 0x34 + iVar3) & 1;
      if ((param_1[0x22] == 1) && ((param_1[0x28] & 0xc0) == 0x40)) {
        bVar5 = bVar5 | 2;
      }
    }
    iVar3 = _p_llm_env;
    iVar4 = *(int *)(_p_llm_env + 8) + iVar7;
    *(byte *)(iVar4 + 0x41) = bVar5;
    memcpy((void *)(iVar4 + 4),auStack_38,6);
    pbStack_30 = param_1 + 2;
    uStack_2c = *(undefined4 *)(param_1 + 0x18);
    bStack_25 = param_1[0x1f];
    uStack_28 = *(undefined2 *)(param_1 + 0x1c);
    piVar6 = (int *)(*(int *)(iVar3 + 8) + iVar7);
    *(byte *)(piVar6 + 10) = bStack_25;
    bStack_26 = param_1[0x1e];
    iVar7 = *piVar6;
    uStack_24 = *(undefined2 *)(iVar7 + 10);
    uStack_22 = *(undefined2 *)(iVar7 + 0xc);
    r_lld_sync_start_eco(*param_1,&pbStack_30);
  }
  else if (cVar1 != '\0') {
    r_assert_err(0,"llm_scan.c",0xa14);
  }
  return 0;
}

