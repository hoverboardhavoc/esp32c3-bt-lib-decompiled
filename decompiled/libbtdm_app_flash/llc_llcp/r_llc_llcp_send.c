/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_llcp.o -> r_llc_llcp_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_llcp_send(int param_1,byte *param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  ushort auStack_22 [3];
  
  if (param_2 == (byte *)0x0) {
    uVar5 = 0xffff;
  }
  else {
    iVar6 = *(int *)(&llc_env + param_1 * 4);
    uVar5 = (uint)*param_2;
    if ((iVar6 != 0) && (uVar5 < 0x23)) {
      auStack_22[0] = *(ushort *)(&DAT_0001077c + uVar5 * 0xc);
      iVar2 = r_ke_malloc(auStack_22[0] + 0xc,2);
      bVar1 = *param_2;
      *(undefined4 *)(iVar2 + 4) = param_3;
      iVar3 = r_co_util_pack(iVar2 + 9,param_2,auStack_22,0x30,(&PTR__LC1_00010778)[(uint)bVar1 * 3]
                            );
      if (iVar3 == 0) {
        *(char *)(iVar2 + 8) = (char)auStack_22[0];
        r_co_list_push_back(iVar6 + 0x28,iVar2);
        r_llc_llcp_tx_check(param_1);
        return;
      }
      uVar5 = (uint)*param_2;
      uVar4 = 0x32b;
      param_1 = iVar3;
      goto _L52;
    }
  }
  uVar4 = 0x339;
_L52:
  r_assert_param(param_1,uVar5,"llc_llcp.c",uVar4);
  return;
}

