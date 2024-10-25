/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_llcp_state_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_llcp_state_set(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(&llc_env + param_1 * 4);
  if (param_3 == 3) {
    if (param_2 == 2) goto _L78;
    uVar2 = 0x1a4;
    uVar1 = 3;
  }
  else {
    if ((param_3 != 0) || (param_2 == 2)) goto _L78;
    uVar2 = 0x1a5;
    uVar1 = 0;
  }
  r_assert_param(param_2,uVar1,"llc.c",uVar2);
_L78:
  if (((iVar3 == 0) || ((*(byte *)(iVar3 + 0x44) & 3) == 3)) ||
     (((int)(uint)*(byte *)(iVar3 + 0x44) >> 2 & 3U) == 3)) {
    return;
  }
  if (param_2 != 1) {
    if (param_2 == 0) {
      if ((param_3 & 0xfffffffc) != 0) {
        r_assert_param(3,param_3,"llc.c",0x1af);
      }
      *(byte *)(iVar3 + 0x44) = (byte)param_3 | *(byte *)(iVar3 + 0x44) & 0xfc;
      return;
    }
    if (param_2 != 2) {
      r_assert_param(param_1,param_2,"llc.c",0x1c0);
      return;
    }
    if ((param_3 & 0xfffffffc) != 0) {
      r_assert_param(3,param_3,"llc.c",0x1b4);
    }
    *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xfc | (byte)param_3;
  }
  if ((param_3 << 2 & 0xfffffff3) != 0) {
    r_assert_param(0xc,param_3,"llc.c",0x1b8);
  }
  *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xf3 | (byte)(param_3 << 2);
  r_llc_llcp_tx_check(param_1);
  return;
}

