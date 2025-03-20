/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
  int iVar4;
  uint uVar5;
  int iVar6;
  ushort uStack_22;
  
  if (param_2 == (byte *)0x0) {
    uVar5 = 0xffff;
  }
  else {
    iVar6 = *(int *)(&llc_env + param_1 * 4);
    uVar5 = (uint)*param_2;
    if ((iVar6 != 0) && (uVar5 < 0x23)) {
      uStack_22 = *(ushort *)(&DAT_00010850 + uVar5 * 0xc);
      iVar2 = r_ke_malloc(uStack_22 + 0xc,2);
      bVar1 = *param_2;
      *(undefined4 *)(iVar2 + 4) = param_3;
      iVar3 = r_co_util_pack(iVar2 + 9,param_2,&uStack_22,0x30,(&PTR__LC1_0001084c)[(uint)bVar1 * 3]
                            );
      if (iVar3 != 0) {
        r_assert_param(*param_2,"llc_llcp.c",0x32d);
      }
      iVar4 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar4 + 0x28) & 0x20) != 0) &&
         (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 2)) {
        r_ble_log_internal_hex(0x20e30016,uStack_22,iVar2 + 9);
      }
      if (iVar3 != 0) {
        return;
      }
      *(char *)(iVar2 + 8) = (char)uStack_22;
      if (*param_2 == 6) {
        r_co_list_push_front();
      }
      else {
        r_co_list_push_back(iVar6 + 0x28,iVar2);
      }
      r_llc_llcp_tx_check(param_1);
      return;
    }
  }
  r_assert_param(param_1,uVar5,"llc_llcp.c",0x346);
  return;
}

