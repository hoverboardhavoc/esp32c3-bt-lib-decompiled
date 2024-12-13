/*
 * Last changed at upstream commit c57c0b11c3c0065a16b66685715100a189ef9b27
 * https://github.com/espressif/esp32c3-bt-lib/commit/c57c0b11c3c0065a16b66685715100a189ef9b27
 * Upstream date: 2024-12-13 13:39:25 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(555b0a2)
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
  int iVar6;
  int *piVar7;
  undefined1 auStack_38 [8];
  byte *pbStack_30;
  undefined4 uStack_2c;
  undefined2 uStack_28;
  byte bStack_26;
  byte bStack_25;
  undefined2 uStack_24;
  undefined2 uStack_22;
  
  iVar6 = (uint)*param_1 * 0x44;
  cVar1 = *(char *)(*(int *)(_p_llm_env + 8) + iVar6 + 0x40);
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
      bVar5 = (byte)*(undefined2 *)(iVar3 + ((uVar2 - 0xc60) / 0x34 & 0xff) * 0x34) & 1;
      if ((param_1[0x28] & 0xc0) == 0x40) {
        bVar5 = bVar5 | 2;
      }
    }
    iVar3 = _p_llm_env;
    iVar4 = *(int *)(_p_llm_env + 8) + iVar6;
    *(byte *)(iVar4 + 0x41) = bVar5;
    memcpy((void *)(iVar4 + 4),auStack_38,6);
    pbStack_30 = param_1 + 2;
    uStack_2c = *(undefined4 *)(param_1 + 0x18);
    piVar7 = (int *)(iVar6 + *(int *)(iVar3 + 8));
    bStack_25 = param_1[0x1f];
    uStack_28 = *(undefined2 *)(param_1 + 0x1c);
    *(byte *)(piVar7 + 10) = bStack_25;
    bStack_26 = param_1[0x1e];
    iVar6 = *piVar7;
    uStack_24 = *(undefined2 *)(iVar6 + 10);
    uStack_22 = *(undefined2 *)(iVar6 + 0xc);
    r_lld_sync_start_eco(*param_1,&pbStack_30);
  }
  else if (cVar1 != '\0') {
    r_assert_err(0,"llm_scan.c",0xa0c);
  }
  return 0;
}

