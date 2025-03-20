/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_rx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_rx(int param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ushort uVar7;
  
  iVar3 = *(int *)(&lld_con_env + param_1 * 4);
  *(ushort *)(iVar3 + 0x84) = *(ushort *)(iVar3 + 0x84) & 0xfffb;
  while (iVar5 = r_lld_rxdesc_check_hack(param_1), iVar5 != 0) {
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar4 = (uint)bVar1 * 0x14;
    uVar7 = *(ushort *)(iVar6 + iVar4 + 2);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar2 = *(ushort *)(iVar6 + iVar4 + 4);
    if (((uVar7 & 1) == 0) && (r_lld_con_rx_sync_time_update(param_1,iVar3), (uVar7 & 8) == 0)) {
      *(undefined4 *)(iVar3 + 0x58) = *(undefined4 *)(iVar3 + 0x50);
      if ((uVar7 & 0x66) == 0) {
        if ((uVar7 & 0x10) == 0) {
          iVar6 = r_emi_get_mem_addr_by_offset(0x400);
          uVar7 = uVar2 >> 8;
          *(undefined2 *)(iVar3 + 0x98) = *(undefined2 *)(iVar6 + param_1 * 0x5a + 0x50);
          if ((uVar7 != 0) && ((uVar2 & 3) != 0)) {
            if ((4 < uVar7) && ((*(ushort *)(iVar3 + 0x84) & 0x20) != 0)) {
              uVar7 = uVar7 - 4;
            }
            iVar6 = r_lld_con_rx_llcp_check(param_1,iVar3,uVar7);
            if (iVar6 == 0) {
              iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
              *(undefined2 *)(iVar4 + 0x12 + iVar6) = 0;
            }
          }
        }
        else {
          *(undefined1 *)(iVar3 + 0x8f) = 2;
          *(ushort *)(iVar3 + 0x84) = *(ushort *)(iVar3 + 0x84) | 0x80;
        }
      }
    }
    else {
      iVar5 = 0;
    }
    r_lld_con_rx_channel_assess(iVar3,iVar5);
    r_lld_rxdesc_free();
  }
  return;
}

