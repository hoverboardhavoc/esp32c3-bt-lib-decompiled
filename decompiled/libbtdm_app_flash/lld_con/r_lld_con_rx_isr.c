/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_rx_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_rx_isr(uint param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  int iVar7;
  
  if (*(int *)(&lld_con_env + param_1 * 4) == 0) {
    r_assert_param(0,"lld_con.c",0xc22);
    return;
  }
  iVar3 = *(int *)(&lld_con_env + param_1 * 4);
  iVar4 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar4 + 0x28) & 0x20) != 0) &&
     (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40c3001b,param_1);
  }
  *(ushort *)(iVar3 + 0x84) = *(ushort *)(iVar3 + 0x84) & 0xfffb;
  while (iVar4 = r_lld_rxdesc_check_hack(param_1), iVar4 != 0) {
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar7 = (uint)bVar1 * 0x14;
    uVar6 = *(ushort *)(iVar5 + iVar7 + 2);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar2 = *(ushort *)(iVar5 + iVar7 + 4);
    if (((uVar6 & 1) == 0) && (r_lld_con_rx_sync_time_update(param_1,iVar3), (uVar6 & 8) == 0)) {
      *(undefined4 *)(iVar3 + 0x58) = *(undefined4 *)(iVar3 + 0x50);
      if ((uVar6 & 0x66) == 0) {
        if ((uVar6 & 0x10) == 0) {
          iVar5 = r_emi_get_mem_addr_by_offset(0x400);
          uVar6 = uVar2 >> 8;
          *(undefined2 *)(iVar3 + 0x98) = *(undefined2 *)(iVar5 + param_1 * 0x5a + 0x50);
          if ((uVar6 != 0) && ((uVar2 & 3) != 0)) {
            if ((4 < uVar6) && ((*(ushort *)(iVar3 + 0x84) & 0x20) != 0)) {
              uVar6 = uVar6 - 4;
            }
            iVar5 = r_lld_con_rx_llcp_check(param_1,iVar3,uVar6);
            if (iVar5 == 0) {
              iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
              *(undefined2 *)(iVar7 + 0x12 + iVar5) = 0;
            }
          }
        }
        else {
          iVar5 = r_sdk_config_get_opts_ext();
          if (((*(uint *)(iVar5 + 0x28) & 0x20) != 0) &&
             (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
            r_ble_log_internal_x1(0x40c30023,(uint)bVar1 << 8 | param_1 | (uint)uVar6 << 0x10);
          }
          *(undefined1 *)(iVar3 + 0x8f) = 2;
          *(ushort *)(iVar3 + 0x84) = *(ushort *)(iVar3 + 0x84) | 0x80;
        }
      }
    }
    else {
      iVar4 = 0;
    }
    r_lld_con_rx_channel_assess(iVar3,iVar4);
    r_lld_rxdesc_free();
  }
  return;
}

