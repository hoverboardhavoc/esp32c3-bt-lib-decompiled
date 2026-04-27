/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> llm_scan.o -> lld_sync_start_req_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_sync_start_req_handler_hack(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  uint uVar2;
  void *__src;
  int iVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  int *piVar7;
  undefined1 auStack_38 [8];
  byte *pbStack_30;
  undefined4 uStack_2c;
  undefined2 uStack_28;
  byte bStack_26;
  byte bStack_25;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined4 uStack_1c;
  
  uStack_1c = param_3;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar5 + 0x18) == '\0') {
    return 0;
  }
  iVar5 = (uint)*param_1 * 0x44;
  cVar1 = *(char *)(*(int *)(_p_llm_env + 8) + iVar5 + 0x40);
  if (cVar1 == '\x0e') {
    uVar2 = (uint)*(ushort *)(param_1 + 0x20);
    if (uVar2 == 0) {
      memcpy(auStack_38,param_1 + 0x23,6);
      bVar6 = param_1[0x22];
    }
    else {
      __src = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                (uVar2 + 0x18 & 0xffff,param_2,*(code **)(_r_plf_funcs_p + 0xbc));
      memcpy(auStack_38,__src,6);
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      bVar6 = (byte)*(undefined2 *)(((uVar2 - 0xc60) / 0x34 & 0xff) * 0x34 + iVar3) & 1;
      if ((param_1[0x22] == 1) && ((param_1[0x28] & 0xc0) == 0x40)) {
        bVar6 = bVar6 | 2;
      }
    }
    iVar3 = _p_llm_env;
    iVar4 = *(int *)(_p_llm_env + 8) + iVar5;
    *(byte *)(iVar4 + 0x41) = bVar6;
    memcpy((void *)(iVar4 + 4),auStack_38,6);
    pbStack_30 = param_1 + 2;
    uStack_2c = *(undefined4 *)(param_1 + 0x18);
    bStack_25 = param_1[0x1f];
    uStack_28 = *(undefined2 *)(param_1 + 0x1c);
    piVar7 = (int *)(*(int *)(iVar3 + 8) + iVar5);
    *(byte *)(piVar7 + 10) = bStack_25;
    bStack_26 = param_1[0x1e];
    iVar5 = *piVar7;
    uStack_24 = *(undefined2 *)(iVar5 + 10);
    uStack_22 = *(undefined2 *)(iVar5 + 0xc);
    (**(code **)(_r_ip_funcs_p + 0x170))(*param_1,&pbStack_30,*(code **)(_r_ip_funcs_p + 0x170));
  }
  else if (cVar1 != '\0') {
    (**(code **)(_r_plf_funcs_p + 8))(0,"llm_scan.c",0xa76,uStack_1c,*(code **)(_r_plf_funcs_p + 8))
    ;
  }
  return 0;
}

