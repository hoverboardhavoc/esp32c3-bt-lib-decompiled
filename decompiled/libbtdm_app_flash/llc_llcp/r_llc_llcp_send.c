/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llc_llcp.o -> r_llc_llcp_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_llcp_send(uint param_1,byte *param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  ushort uStack_22;
  
  iVar5 = *(int *)(&llc_env + param_1 * 4);
  if (param_2 == (byte *)0x0) {
    uVar4 = 0xffff;
  }
  else {
    uVar4 = (uint)*param_2;
    if ((iVar5 != 0) && (uVar4 < 0x23)) {
      uStack_22 = *(ushort *)(llcp_pdu_handler + uVar4 * 0xc + 8);
      iVar2 = r_ke_malloc(uStack_22 + 0xc,2);
      bVar1 = *param_2;
      *(undefined4 *)(iVar2 + 4) = param_3;
      iVar3 = r_co_util_pack(iVar2 + 9,param_2,&uStack_22,0x30,
                             *(undefined4 *)(llcp_pdu_handler + (uint)bVar1 * 0xc + 4));
      if (iVar3 != 0) {
        r_assert_param(*param_2,"llc_llcp.c",0x33b);
      }
      r_ble_log_internal_x1(0x406f00a1,(uint)*param_2 << 8 | param_1);
      r_ble_log_internal_hex(0x406f00a2,uStack_22,iVar2 + 9);
      if (iVar3 == 0) {
        *(char *)(iVar2 + 8) = (char)uStack_22;
        r_co_list_push_back(iVar5 + 0x28,iVar2);
        r_llc_llcp_tx_check_hack(param_1);
      }
      else {
        r_ble_log_internal_x1(0x806f00a3,(uint)*param_2 << 0x10 | param_1 | iVar3 << 8);
      }
      return;
    }
  }
  r_assert_param(param_1,uVar4,"llc_llcp.c",0x351);
  return;
}

