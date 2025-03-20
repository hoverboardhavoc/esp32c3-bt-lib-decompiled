/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app -> llc_llcp.o -> r_llc_llcp_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_llcp_send(int param_1,byte *param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  code *pcVar6;
  int iVar7;
  ushort uStack_22;
  
  if (((param_2 == (byte *)0x0) || (iVar7 = *(int *)(&llc_env + param_1 * 4), iVar7 == 0)) ||
     (0x22 < *param_2)) {
    pcVar6 = *(code **)(_r_plf_funcs_p + 0xc);
    if (param_2 == (byte *)0x0) {
      uVar4 = 0xffff;
    }
    else {
      uVar4 = (uint)*param_2;
    }
    uVar5 = 0x346;
  }
  else {
    uStack_22 = *(ushort *)(&DAT_000108f4 + (uint)*param_2 * 0xc);
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x120))
                      (uStack_22 + 0xc,2,*(code **)(_r_modules_funcs_p + 0x120));
    bVar1 = *param_2;
    *(undefined4 *)(iVar2 + 4) = param_3;
    iVar3 = (**(code **)(_r_modules_funcs_p + 0x10))
                      (iVar2 + 9,param_2,&uStack_22,0x30,(&PTR__LC1_000108f0)[(uint)bVar1 * 3],
                       *(code **)(_r_modules_funcs_p + 0x10));
    if (iVar3 == 0) {
      *(char *)(iVar2 + 8) = (char)uStack_22;
      if (*param_2 == 6) {
        pcVar6 = *(code **)(_r_modules_funcs_p + 0x4c);
      }
      else {
        pcVar6 = *(code **)(_r_modules_funcs_p + 0x44);
      }
      (*pcVar6)(iVar7 + 0x28,iVar2,pcVar6);
      (**(code **)(_r_ip_funcs_p + 0x5b8))(param_1,*(code **)(_r_ip_funcs_p + 0x5b8));
      return;
    }
    uVar4 = (uint)*param_2;
    pcVar6 = *(code **)(_r_plf_funcs_p + 0xc);
    uVar5 = 0x32d;
    param_1 = iVar3;
  }
  (*pcVar6)(param_1,uVar4,"llc_llcp.c",uVar5,pcVar6);
  return;
}

