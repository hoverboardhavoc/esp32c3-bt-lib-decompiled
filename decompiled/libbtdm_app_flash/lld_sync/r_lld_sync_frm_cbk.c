/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_frm_cbk(undefined4 param_1,uint param_2,int param_3)

{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  short sVar10;
  uint uVar11;
  int iVar12;
  char acStack_41 [16];
  char acStack_31 [9];
  
  iVar7 = r_sdk_config_get_opts();
  if (*(byte *)(iVar7 + 0xd) <= param_2) {
    r_assert_param(param_2,param_3,"lld_sync.c",0x46c);
  }
  if (param_3 == 1) {
    iVar7 = 1;
  }
  else {
    if (param_3 != 0) {
      if (param_3 == 2) {
        param_2 = param_2 & 0xff;
        if (*(int *)(&lld_sync_env + param_2 * 4) == 0) {
          r_assert_err(0,"lld_sync.c",0x433);
          return;
        }
        iVar7 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar7 + 0x28) & 0x80) != 0) &&
           (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 2)) {
          r_ble_log_internal_x1(0x20a2000c,param_2);
        }
        iVar7 = *(int *)(&lld_sync_env + param_2 * 4);
        while (iVar6 = r_lld_rxdesc_check_hack(param_2), iVar6 != 0) {
          if (*(ushort *)(iVar7 + 0x52) < 0x673) {
            bVar3 = *(char *)(iVar7 + 99) == '\0';
            r_lld_sync_process_pkt_rx_aux_sync_ind(param_2,bVar3);
            r_lld_sync_process_pkt_rx_pkt_check(param_2,bVar3);
          }
          r_lld_rxdesc_free();
        }
        return;
      }
      if (param_3 != 4) {
        r_assert_param(param_2,param_3,"lld_sync.c",0x482);
        return;
      }
      param_2 = param_2 & 0xff;
      iVar7 = *(int *)(&lld_sync_env + param_2 * 4);
      if (iVar7 == 0) {
        r_assert_err(0,"lld_sync.c",0x45f);
        return;
      }
      iVar6 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar6 + 0x28) & 0x80) != 0) &&
         (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 3)) {
        r_ble_log_internal_x2
                  (0x40420009,
                   (uint)*(byte *)(iVar7 + 0x5b) << 0x10 | (uint)*(byte *)(iVar7 + 99) << 8 |
                   param_2,*(undefined2 *)(iVar7 + 0x4a));
      }
      r_sch_arb_remove(iVar7,1);
      if (*(char *)(iVar7 + 99) == '\x01') {
        r_lld_sync_trunc_ind(param_2);
        *(undefined1 *)(iVar7 + 99) = 0;
      }
      param_2 = (uint)*(byte *)(iVar7 + 0x55);
      if (*(char *)(iVar7 + 0x5b) != '\x02') {
        iVar7 = 1;
        goto r_lld_sync_sched;
      }
      goto code_r0x0001041a;
    }
    iVar7 = 0;
  }
  param_2 = param_2 & 0xff;
  iVar6 = *(int *)(&lld_sync_env + param_2 * 4);
  if (iVar6 == 0) {
    r_assert_err(0,"lld_sync.c",0x41b);
    return;
  }
  bVar1 = *(byte *)(iVar6 + 0x55);
  iVar5 = r_sdk_config_get_opts_ext(param_1);
  if (((*(uint *)(iVar5 + 0x28) & 0x80) != 0) &&
     (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40420008,(uint)*(ushort *)(iVar6 + 0x4a) << 0x10 | iVar7 << 8 | param_2)
    ;
  }
  r_sch_arb_remove(iVar6,1);
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  iVar12 = (uint)bVar1 * 0x5a + 0x18;
  if ((*(ushort *)(iVar5 + iVar12) >> 10 & 1) != 0) {
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    uVar2 = *(ushort *)(iVar5 + iVar12);
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar5 + iVar12) = uVar2 & 0xfbff;
    if (*(char *)(iVar6 + 0x62) == '\x01') {
      r_lld_sync_trunc_ind(param_2);
    }
    *(undefined1 *)(iVar6 + 99) = 0;
  }
  r_lld_sync_process_pkt_rx(param_2);
  if (((*(char *)(iVar6 + 99) == '\x02') ||
      ((*(char *)(iVar6 + 100) == '\0' && (*(char *)(iVar6 + 99) == '\x01')))) &&
     (*(char *)(iVar6 + 0x62) == '\x01')) {
    r_lld_sync_trunc_ind(param_2);
    *(undefined1 *)(iVar6 + 99) = 0;
  }
  if (*(char *)(iVar6 + 0x5b) != '\x02') {
r_lld_sync_sched:
    iVar6 = *(int *)(&lld_sync_env + param_2 * 4);
    acStack_41[0] = (char)iVar7;
    acStack_31[0] = '\0';
    do {
      bVar1 = DAT_00013065;
      if (acStack_41[0] == '\0') {
        *(undefined1 *)(iVar6 + 0x16) = co_sca2ppm;
      }
      else {
        if (0xff < (uint)*(byte *)(iVar6 + 0x16) + (uint)DAT_00013065) {
          r_assert_err(0,"lld_sync.c",0x337);
        }
        *(byte *)(iVar6 + 0x16) = bVar1 + *(char *)(iVar6 + 0x16);
      }
      if (*(char *)(iVar6 + 99) == '\x01') {
        uVar8 = *(uint *)(iVar6 + 0x2c);
        bVar1 = *(byte *)(iVar6 + 0x31);
        iVar7 = (int)*(short *)(iVar6 + 0x28);
        uVar11 = *(uint *)(iVar6 + 0x24);
      }
      else {
        iVar7 = 1;
        if ((((*(char *)(iVar6 + 100) != '\0') && (*(char *)(iVar6 + 0x62) == '\0')) &&
            (*(short *)(iVar6 + 0x4c) != 0)) && (iVar7 = -1, acStack_41[0] == '\0')) {
          sVar10 = *(short *)(iVar6 + 0x4c) + 1;
          iVar7 = (int)sVar10;
          *(short *)(iVar6 + 0x4e) = sVar10 + *(short *)(iVar6 + 0x4a);
        }
        *(short *)(iVar6 + 0x4a) = *(short *)(iVar6 + 0x4a) + (short)iVar7;
        *(uint *)(iVar6 + 0x44) =
             iVar7 * *(int *)(iVar6 + 0x40) + *(int *)(iVar6 + 0x44) & 0xfffffff;
        iVar7 = r_lld_read_clock();
        if ((iVar7 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar6 + 0x44)) & 0xfffffff) < 0x8000001)
        {
          iVar7 = r_lld_read_clock();
          uVar8 = iVar7 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar6 + 0x44)) & 0xfffffff;
          if (uVar8 != 0) {
            uVar2 = *(ushort *)(iVar6 + 0x4a);
            uVar9 = *(uint *)(iVar6 + 0x40);
            if (((uint)uVar2 - (uint)*(ushort *)(iVar6 + 0x4e) & 0xffff) < 0x7fff) {
              iVar7 = ((uVar9 - 1) + uVar8) / uVar9 << 0x10;
            }
            else {
              iVar7 = ((*(ushort *)(iVar6 + 0x4e) + 1) - (uint)uVar2) * 0x10000;
              *(undefined1 *)(iVar6 + 100) = 0;
            }
            *(ushort *)(iVar6 + 0x4a) = (short)((uint)iVar7 >> 0x10) + uVar2;
            *(uint *)(iVar6 + 0x44) = (iVar7 >> 0x10) * uVar9 + *(int *)(iVar6 + 0x44) & 0xfffffff;
          }
        }
        else {
          r_lld_read_clock();
        }
        if (*(char *)(iVar6 + 0x57) == '\0') {
          uVar8 = *(int *)(iVar6 + 0x40) * 6;
        }
        else {
          uVar8 = *(uint *)(iVar6 + 0x34);
        }
        if (uVar8 < (*(int *)(iVar6 + 0x44) - *(int *)(iVar6 + 0x3c) & 0xfffffffU)) {
          iVar7 = r_sdk_config_get_opts_ext();
          if (((*(uint *)(iVar7 + 0x28) & 0x80) != 0) &&
             (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
            r_ble_log_internal_x3
                      (0x40020004,
                       (uint)*(ushort *)(iVar6 + 0x4a) << 0x10 | (uint)*(byte *)(iVar6 + 0x57) << 8
                       | param_2,uVar8,*(undefined4 *)(iVar6 + 0x44));
          }
_L229:
          r_lld_sync_cleanup(param_2,8);
          return;
        }
        iVar7 = r_rwip_active_check();
        uVar8 = 0x14;
        if (iVar7 == 0) {
          uVar8 = (uint)*(ushort *)(_p_lld_env + 0xd4);
        }
        iVar7 = (((uint)((*(int *)(iVar6 + 0x44) - *(int *)(iVar6 + 0x38)) * 0x10) >> 8) *
                (*(ushort *)(&co_sca2ppm + (uint)*(byte *)(iVar6 + 0x5a) * 2) + uVar8)) / 100 + 0x10
        ;
        uVar8 = iVar7 * 2;
        uVar11 = *(int *)(iVar6 + 0x44) - uVar8 / 0x271 & 0xfffffff;
        uVar9 = (uint)*(ushort *)(iVar6 + 0x48) + iVar7 * -2 + (uVar8 / 0x271) * 0x271;
        iVar7 = (int)(short)uVar9;
        if (iVar7 < 0) {
          uVar11 = uVar11 - 1 & 0xfffffff;
          iVar7 = (int)(((uVar9 & 0xffff) + 0x271) * 0x10000) >> 0x10;
        }
        if (*(char *)(iVar6 + 0x57) == '\0') {
          iVar5 = 300;
          if (*(char *)(iVar6 + 0x56) == '\0') {
            iVar5 = 0x1e;
          }
          uVar8 = uVar8 + iVar5;
          if (((uint)(*(int *)(iVar6 + 0x40) * 0x271) >> 1) - 0x96 < uVar8 >> 1) {
            iVar7 = r_sdk_config_get_opts_ext();
            if (((*(uint *)(iVar7 + 0x28) & 0x80) != 0) &&
               (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
              r_ble_log_internal_x2
                        (0x40020005,(uint)*(ushort *)(iVar6 + 0x4a) << 0x10 | param_2,uVar8);
            }
            goto _L229;
          }
        }
        *(undefined2 *)(iVar6 + 0x52) = 0;
        bVar1 = *(byte *)(iVar6 + 0x58);
      }
      uVar9 = (uint)_DAT_0001306e;
      *(uint *)(iVar6 + 4) = uVar11;
      uVar2 = *(ushort *)(&lld_sync_max_aux_dur_tab + (uint)bVar1 * 2);
      *(int *)(iVar6 + 8) = iVar7;
      uVar8 = uVar8 * 2 + uVar9 + (uint)uVar2 * 2;
      if (uVar8 < 0x61a81) {
        *(uint *)(iVar6 + 0x10) = uVar8;
      }
      else {
        *(undefined4 *)(iVar6 + 0x10) = 400000;
      }
      r_lld_sync_insert_eco(param_2,acStack_41,acStack_31);
      if (acStack_31[0] != '\0') {
        return;
      }
    } while( true );
  }
code_r0x0001041a:
  if (*(int *)(&lld_sync_env + param_2 * 4) != 0) {
    iVar7 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar7 + 0x28) & 0x80) != 0) &&
       (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
      r_ble_log_internal_x1
                (0x40020002,
                 (uint)*(ushort *)(*(int *)(&lld_sync_env + param_2 * 4) + 0x4a) << 0x10 | param_2);
    }
    puVar4 = (undefined1 *)r_ke_msg_alloc(0x205,0,0xff,2);
    *puVar4 = (char)param_2;
    puVar4[1] = 0;
    r_ke_msg_send();
    r_ke_free(*(undefined4 *)(&lld_sync_env + param_2 * 4));
    *(undefined4 *)(&lld_sync_env + param_2 * 4) = 0;
  }
  return;
}

