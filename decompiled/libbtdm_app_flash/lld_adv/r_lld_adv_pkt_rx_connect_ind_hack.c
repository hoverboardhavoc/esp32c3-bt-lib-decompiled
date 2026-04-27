/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_pkt_rx_connect_ind_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_adv_pkt_rx_connect_ind_hack(uint param_1)

{
  byte bVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  undefined1 auStack_5c [8];
  undefined4 uStack_54;
  undefined2 uStack_50;
  undefined4 uStack_4c;
  undefined2 uStack_48;
  undefined4 uStack_44;
  undefined2 uStack_40;
  uint uStack_38;
  byte bStack_31;
  ushort uStack_30;
  ushort uStack_2e;
  ushort uStack_2c;
  ushort uStack_2a;
  undefined1 auStack_28 [4];
  byte bStack_24;
  byte bStack_23;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  uVar7 = (uint)bVar1 << 8 | param_1;
  r_ble_log_internal_x1(0x40a000e1,uVar7);
  iVar2 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar6 = (uint)bVar1 * 0x14;
  if ((*(ushort *)(iVar2 + iVar6 + 4) & 0xf) == 5) {
    iVar2 = r_emi_get_mem_addr_by_offset(0x1000);
    pvVar3 = (void *)r_emi_get_mem_addr_by_offset(*(undefined2 *)(iVar6 + 0x12 + iVar2));
    memcpy(&uStack_44,pvVar3,0x22);
    r_ble_log_internal_hex(0x20a000e2,0x22,&uStack_44);
    if ((uStack_38 & 0xffff) == uStack_38 >> 0x10) {
      r_ble_log_internal_x2(0x80a000e3,uVar7);
      return 0;
    }
    iVar2 = r_sdk_config_get_opts_ext();
    if ((*(char *)(iVar2 + 0x24) != '\0') &&
       (iVar2 = r_lld_adv_utils_verify_aa(uStack_38), iVar2 == 0)) {
      r_ble_log_internal_x2(0x80a000e4,uVar7);
      return 0;
    }
    if (((((((uStack_2a - 10 & 0xffff) < 0xc77) &&
           (uVar4 = (uint)uStack_2e, _g_ble_con_interval_min <= uVar4)) && (uVar4 < 0xc81)) &&
         (((uStack_2c < 500 && ((ushort)(uStack_2c + 1) * uVar4 < (uint)uStack_2a << 2)) &&
          ((uVar4 = r_co_nb_good_le_channels(auStack_28,uStack_38), 1 < uVar4 &&
           (((bStack_24 & 0xe0) == 0 && ((byte)((bStack_23 & 0x1f) - 5) < 0xc)))))))) &&
        (uVar4 = (uint)uStack_2e, uStack_30 <= uVar4)) && (bStack_31 != 0)) {
      iVar2 = 8;
      if (uVar4 < 10) {
        iVar2 = uVar4 - 1;
      }
      if ((int)(uint)bStack_31 <= iVar2) {
        iVar2 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar7 = (uint)*(ushort *)(iVar6 + 0xe + iVar2);
        if (uVar7 == 0) {
          iVar2 = r_emi_get_mem_addr_by_offset(0x1000);
          uVar5 = *(ushort *)(iVar2 + iVar6 + 4) >> 6 & 1;
        }
        else {
          pvVar3 = (void *)r_emi_get_mem_addr_by_offset(uVar7 + 0x18 & 0xffff);
          memcpy(auStack_5c,pvVar3,6);
          iVar6 = r_emi_get_mem_addr_by_offset(0xc60);
          iVar2 = ((uVar7 - 0xc60) / 0x34 & 0xff) * 0x34;
          uVar5 = *(ushort *)(iVar6 + iVar2);
          iVar6 = r_emi_get_mem_addr_by_offset(0xc60);
          uVar5 = uVar5 & 1;
          if ((((*(ushort *)(iVar6 + iVar2) >> 1 & 1) != 0) &&
              (iVar6 = r_emi_get_mem_addr_by_offset(0xc60),
              (*(ushort *)(iVar6 + iVar2) >> 3 & 1) != 0)) &&
             (iVar6 = r_co_bdaddr_compare(&uStack_44,auStack_5c), iVar6 == 0)) {
            uVar5 = uVar5 | 2;
            uStack_54 = uStack_44;
            uStack_50 = uStack_40;
            goto _L811;
          }
          iVar6 = r_emi_get_mem_addr_by_offset(0xc60);
          if (((*(ushort *)(iVar6 + iVar2) >> 1 & 1) != 0) &&
             (iVar6 = r_emi_get_mem_addr_by_offset(0xc60),
             (*(ushort *)(iVar2 + iVar6) >> 0xb & 1) == 0)) {
            r_assert_err(0,0x10000,0x8a2);
          }
        }
        uStack_54 = 0;
        uStack_50 = 0;
_L811:
        iVar2 = r_emi_get_mem_addr_by_offset(0x400);
        if ((*(ushort *)(param_1 * 0x5a + 0x14 + iVar2) >> 2 & 1) == 0) {
          uStack_4c = 0;
          uStack_48 = 0;
        }
        else {
          iVar2 = r_emi_get_mem_addr_by_offset(0x400);
          uVar7 = (*(ushort *)(param_1 * 0x5a + 0x2c + iVar2) - 0xc60) / 0x34;
          uVar4 = uVar7 & 0xff;
          if (9 < uVar4) {
            r_assert_err(0,0x10000,0x8b6);
          }
          iVar6 = r_emi_get_mem_addr_by_offset(0xc60);
          iVar2 = (uVar7 & 0xff) * 0x34;
          if ((*(ushort *)(iVar6 + iVar2) >> 5 & 1) == 0) {
            r_assert_err(0,0x10000,0x8b7);
          }
          iVar6 = r_emi_get_mem_addr_by_offset(0xc60);
          if ((*(ushort *)(iVar2 + iVar6) >> 7 & 1) == 0) {
            r_assert_err(0,0x10000,0x8b8);
          }
          pvVar3 = (void *)r_emi_get_mem_addr_by_offset(uVar4 * 0x34 + 0xc8e);
          memcpy(&uStack_4c,pvVar3,6);
        }
        r_lld_adv_pkt_rx_connect_post(param_1,&uStack_44,auStack_5c,&uStack_54,&uStack_4c,uVar5);
        return 1;
      }
    }
    r_ble_log_internal_x1(0x80a000e5,uVar7);
    r_ble_log_internal_hex(0x80a000e6,0x22,&uStack_44);
  }
  else {
    r_assert_err(0,0x10000,0x86a);
  }
  return 0;
}

