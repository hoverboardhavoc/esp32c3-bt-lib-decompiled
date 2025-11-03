/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_pkt_rx_connect_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_adv_pkt_rx_connect_ind(uint param_1)

{
  byte bVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  void *pvVar5;
  uint uVar6;
  uint uVar7;
  undefined1 auStack_5c [8];
  undefined4 uStack_54;
  undefined2 uStack_50;
  undefined4 uStack_4c;
  undefined2 uStack_48;
  undefined4 uStack_44;
  undefined2 uStack_40;
  byte bStack_31;
  ushort uStack_30;
  ushort uStack_2e;
  ushort uStack_2c;
  ushort uStack_2a;
  undefined1 auStack_28 [4];
  byte bStack_24;
  byte bStack_23;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar2 = (uint)bVar1 * 0x14;
  if ((*(ushort *)(iVar4 + iVar2 + 4) & 0xf) == 5) {
    iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
    pvVar5 = (void *)r_emi_get_mem_addr_by_offset(*(undefined2 *)(iVar2 + 0x12 + iVar4));
    memcpy(&uStack_44,pvVar5,0x22);
    if ((((((uStack_2a - 10 & 0xffff) < 0xc77) && ((uStack_2e - 6 & 0xffff) < 0xc7b)) &&
         (uStack_2c < 500)) &&
        ((((uint)(ushort)(uStack_2c + 1) * (uint)uStack_2e < (uint)uStack_2a << 2 &&
          (uVar6 = r_co_nb_good_le_channels(auStack_28), 1 < uVar6)) &&
         (((bStack_24 & 0xe0) == 0 &&
          (((byte)((bStack_23 & 0x1f) - 5) < 0xc && (uVar6 = (uint)uStack_2e, uStack_30 <= uVar6))))
         )))) && (bStack_31 != 0)) {
      iVar4 = 8;
      if (uVar6 < 10) {
        iVar4 = uVar6 - 1;
      }
      if ((int)(uint)bStack_31 <= iVar4) {
        iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar6 = (uint)*(ushort *)(iVar2 + 0xe + iVar4);
        if (uVar6 == 0) {
          iVar4 = r_emi_get_mem_addr_by_offset(0x1000);
          uVar3 = *(ushort *)(iVar4 + iVar2 + 4) >> 6 & 1;
        }
        else {
          pvVar5 = (void *)r_emi_get_mem_addr_by_offset(uVar6 + 0x18 & 0xffff);
          memcpy(auStack_5c,pvVar5,6);
          iVar4 = r_emi_get_mem_addr_by_offset(0xc60);
          iVar2 = ((uVar6 - 0xc60) / 0x34 & 0xff) * 0x34;
          uVar3 = *(ushort *)(iVar4 + iVar2);
          iVar4 = r_emi_get_mem_addr_by_offset(0xc60);
          uVar3 = uVar3 & 1;
          if ((((*(ushort *)(iVar4 + iVar2) >> 1 & 1) != 0) &&
              (iVar4 = r_emi_get_mem_addr_by_offset(0xc60),
              (*(ushort *)(iVar4 + iVar2) >> 3 & 1) != 0)) &&
             (iVar4 = r_co_bdaddr_compare(&uStack_44,auStack_5c), iVar4 == 0)) {
            uVar3 = uVar3 | 2;
            uStack_54 = uStack_44;
            uStack_50 = uStack_40;
            goto _L778;
          }
          iVar4 = r_emi_get_mem_addr_by_offset(0xc60);
          if (((*(ushort *)(iVar4 + iVar2) >> 1 & 1) != 0) &&
             (iVar4 = r_emi_get_mem_addr_by_offset(0xc60),
             (*(ushort *)(iVar2 + iVar4) >> 0xb & 1) == 0)) {
            r_assert_err(0,0x10000,0x824);
          }
        }
        uStack_54 = 0;
        uStack_50 = 0;
_L778:
        iVar2 = r_emi_get_mem_addr_by_offset(0x400);
        if ((*(ushort *)(param_1 * 0x5a + 0x14 + iVar2) >> 2 & 1) == 0) {
          uStack_4c = 0;
          uStack_48 = 0;
        }
        else {
          iVar2 = r_emi_get_mem_addr_by_offset(0x400);
          uVar6 = (*(ushort *)(param_1 * 0x5a + 0x2c + iVar2) - 0xc60) / 0x34;
          uVar7 = uVar6 & 0xff;
          if (9 < uVar7) {
            r_assert_err(0,0x10000,0x83b);
          }
          iVar4 = r_emi_get_mem_addr_by_offset(0xc60);
          iVar2 = (uVar6 & 0xff) * 0x34;
          if ((*(ushort *)(iVar4 + iVar2) >> 5 & 1) == 0) {
            r_assert_err(0,0x10000,0x83c);
          }
          iVar4 = r_emi_get_mem_addr_by_offset(0xc60);
          if ((*(ushort *)(iVar2 + iVar4) >> 7 & 1) == 0) {
            r_assert_err(0,0x10000,0x83d);
          }
          pvVar5 = (void *)r_emi_get_mem_addr_by_offset(uVar7 * 0x34 + 0xc8e);
          memcpy(&uStack_4c,pvVar5,6);
        }
        r_lld_adv_pkt_rx_connect_post(param_1,&uStack_44,auStack_5c,&uStack_54,&uStack_4c,uVar3);
        return 1;
      }
    }
    r_ble_log_internal_x1(0x80a00062,(uint)bVar1 << 8 | param_1);
    r_ble_log_internal_hex(0x80a00063,0x22,&uStack_44);
  }
  else {
    r_assert_err(0,0x10000,0x7f1);
  }
  return 0;
}

