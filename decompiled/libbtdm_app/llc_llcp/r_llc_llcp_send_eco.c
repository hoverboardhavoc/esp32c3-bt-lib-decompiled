/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app -> llc_llcp.o -> r_llc_llcp_send_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_llcp_send_eco(int param_1,byte *param_2,code *param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  code *pcVar7;
  ushort uStack_22;
  
  bVar1 = *param_2;
  if (bVar1 == 0) {
    param_3 = llc_llcp_conn_update_ind_ack;
  }
  else if (bVar1 == 1) {
    param_3 = *(code **)(_r_ip_funcs_p + 0x8f4);
  }
  else if (bVar1 == 0x18) {
    param_3 = llc_llcp_phy_update_ind_ack;
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if (*(char *)(iVar4 + 0x18) == '\0') {
      (**(code **)(_r_plf_funcs_p + 8))(0,"llc_llcp.c",0x1e9,*(code **)(_r_plf_funcs_p + 8));
    }
  }
  if (((param_2 == (byte *)0x0) || (iVar4 = *(int *)(&llc_env + param_1 * 4), iVar4 == 0)) ||
     (0x22 < *param_2)) {
    pcVar7 = *(code **)(_r_plf_funcs_p + 0xc);
    if (param_2 == (byte *)0x0) {
      uVar5 = 0xffff;
    }
    else {
      uVar5 = (uint)*param_2;
    }
    uVar6 = 0x346;
  }
  else {
    uStack_22 = *(ushort *)(&DAT_000108f4 + (uint)*param_2 * 0xc);
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x120))
                      (uStack_22 + 0xc,2,*(code **)(_r_modules_funcs_p + 0x120));
    bVar1 = *param_2;
    *(code **)(iVar2 + 4) = param_3;
    iVar3 = (**(code **)(_r_modules_funcs_p + 0x10))
                      (iVar2 + 9,param_2,&uStack_22,0x30,(&PTR__LC1_000108f0)[(uint)bVar1 * 3],
                       *(code **)(_r_modules_funcs_p + 0x10));
    if (iVar3 == 0) {
      *(char *)(iVar2 + 8) = (char)uStack_22;
      if (*param_2 == 6) {
        pcVar7 = *(code **)(_r_modules_funcs_p + 0x4c);
      }
      else {
        pcVar7 = *(code **)(_r_modules_funcs_p + 0x44);
      }
      (*pcVar7)(iVar4 + 0x28,iVar2,pcVar7);
      (**(code **)(_r_ip_funcs_p + 0x5b8))(param_1,*(code **)(_r_ip_funcs_p + 0x5b8));
      return;
    }
    uVar5 = (uint)*param_2;
    pcVar7 = *(code **)(_r_plf_funcs_p + 0xc);
    uVar6 = 0x32d;
    param_1 = iVar3;
  }
  (*pcVar7)(param_1,uVar5,"llc_llcp.c",uVar6,pcVar7);
  return;
}

