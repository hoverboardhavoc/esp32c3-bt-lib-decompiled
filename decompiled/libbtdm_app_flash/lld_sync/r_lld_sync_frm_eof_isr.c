/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_frm_eof_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_frm_eof_isr(uint param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  short sVar8;
  uint uVar9;
  int iVar10;
  char acStack_41 [16];
  char acStack_31 [9];
  
  iVar3 = *(int *)(&lld_sync_env + param_1 * 4);
  if (iVar3 == 0) {
    r_assert_err(0,"lld_sync.c",0x41b);
    return;
  }
  bVar1 = *(byte *)(iVar3 + 0x55);
  iVar5 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar5 + 0x28) & 0x80) != 0) &&
     (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
    r_ble_log_internal_x1
              (0x40420008,(uint)*(ushort *)(iVar3 + 0x4a) << 0x10 | param_2 << 8 | param_1);
  }
  r_sch_arb_remove(iVar3,1);
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  iVar10 = (uint)bVar1 * 0x5a + 0x18;
  if ((*(ushort *)(iVar5 + iVar10) >> 10 & 1) != 0) {
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    uVar2 = *(ushort *)(iVar5 + iVar10);
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar5 + iVar10) = uVar2 & 0xfbff;
    if (*(char *)(iVar3 + 0x62) == '\x01') {
      r_lld_sync_trunc_ind(param_1);
    }
    *(undefined1 *)(iVar3 + 99) = 0;
  }
  r_lld_sync_process_pkt_rx(param_1);
  if (((*(char *)(iVar3 + 99) == '\x02') ||
      ((*(char *)(iVar3 + 100) == '\0' && (*(char *)(iVar3 + 99) == '\x01')))) &&
     (*(char *)(iVar3 + 0x62) == '\x01')) {
    r_lld_sync_trunc_ind(param_1);
    *(undefined1 *)(iVar3 + 99) = 0;
  }
  if (*(char *)(iVar3 + 0x5b) == '\x02') {
    if (*(int *)(&lld_sync_env + param_1 * 4) != 0) {
      iVar3 = r_sdk_config_get_opts_ext();
      if (((*(uint *)(iVar3 + 0x28) & 0x80) != 0) &&
         (iVar3 = r_sdk_config_get_opts_ext(), *(byte *)(iVar3 + 0x2c) < 3)) {
        r_ble_log_internal_x1
                  (0x40020002,
                   (uint)*(ushort *)(*(int *)(&lld_sync_env + param_1 * 4) + 0x4a) << 0x10 | param_1
                  );
      }
      puVar4 = (undefined1 *)r_ke_msg_alloc(0x205,0,0xff,2);
      *puVar4 = (char)param_1;
      puVar4[1] = 0;
      r_ke_msg_send();
      r_ke_free(*(undefined4 *)(&lld_sync_env + param_1 * 4));
      *(undefined4 *)(&lld_sync_env + param_1 * 4) = 0;
    }
    return;
  }
  iVar3 = *(int *)(&lld_sync_env + param_1 * 4);
  acStack_41[0] = (char)param_2;
  acStack_31[0] = '\0';
  do {
    bVar1 = DAT_00013065;
    if (acStack_41[0] == '\0') {
      *(undefined1 *)(iVar3 + 0x16) = co_sca2ppm;
    }
    else {
      if (0xff < (uint)*(byte *)(iVar3 + 0x16) + (uint)DAT_00013065) {
        r_assert_err(0,"lld_sync.c",0x337);
      }
      *(byte *)(iVar3 + 0x16) = bVar1 + *(char *)(iVar3 + 0x16);
    }
    if (*(char *)(iVar3 + 99) == '\x01') {
      uVar6 = *(uint *)(iVar3 + 0x2c);
      bVar1 = *(byte *)(iVar3 + 0x31);
      iVar5 = (int)*(short *)(iVar3 + 0x28);
      uVar9 = *(uint *)(iVar3 + 0x24);
    }
    else {
      iVar5 = 1;
      if ((((*(char *)(iVar3 + 100) != '\0') && (*(char *)(iVar3 + 0x62) == '\0')) &&
          (*(short *)(iVar3 + 0x4c) != 0)) && (iVar5 = -1, acStack_41[0] == '\0')) {
        sVar8 = *(short *)(iVar3 + 0x4c) + 1;
        iVar5 = (int)sVar8;
        *(short *)(iVar3 + 0x4e) = sVar8 + *(short *)(iVar3 + 0x4a);
      }
      *(short *)(iVar3 + 0x4a) = *(short *)(iVar3 + 0x4a) + (short)iVar5;
      *(uint *)(iVar3 + 0x44) = iVar5 * *(int *)(iVar3 + 0x40) + *(int *)(iVar3 + 0x44) & 0xfffffff;
      iVar5 = r_lld_read_clock();
      if ((iVar5 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar3 + 0x44)) & 0xfffffff) < 0x8000001) {
        iVar5 = r_lld_read_clock();
        uVar6 = iVar5 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar3 + 0x44)) & 0xfffffff;
        if (uVar6 != 0) {
          uVar2 = *(ushort *)(iVar3 + 0x4a);
          uVar7 = *(uint *)(iVar3 + 0x40);
          if (((uint)uVar2 - (uint)*(ushort *)(iVar3 + 0x4e) & 0xffff) < 0x7fff) {
            iVar5 = ((uVar7 - 1) + uVar6) / uVar7 << 0x10;
          }
          else {
            iVar5 = ((*(ushort *)(iVar3 + 0x4e) + 1) - (uint)uVar2) * 0x10000;
            *(undefined1 *)(iVar3 + 100) = 0;
          }
          *(ushort *)(iVar3 + 0x4a) = (short)((uint)iVar5 >> 0x10) + uVar2;
          *(uint *)(iVar3 + 0x44) = (iVar5 >> 0x10) * uVar7 + *(int *)(iVar3 + 0x44) & 0xfffffff;
        }
      }
      else {
        r_lld_read_clock();
      }
      if (*(char *)(iVar3 + 0x57) == '\0') {
        uVar6 = *(int *)(iVar3 + 0x40) * 6;
      }
      else {
        uVar6 = *(uint *)(iVar3 + 0x34);
      }
      if (uVar6 < (*(int *)(iVar3 + 0x44) - *(int *)(iVar3 + 0x3c) & 0xfffffffU)) {
        iVar5 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar5 + 0x28) & 0x80) != 0) &&
           (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
          r_ble_log_internal_x3
                    (0x40020004,
                     (uint)*(ushort *)(iVar3 + 0x4a) << 0x10 | (uint)*(byte *)(iVar3 + 0x57) << 8 |
                     param_1,uVar6,*(undefined4 *)(iVar3 + 0x44));
        }
_L229:
        r_lld_sync_cleanup(param_1,8);
        return;
      }
      iVar5 = r_rwip_active_check();
      uVar6 = 0x14;
      if (iVar5 == 0) {
        uVar6 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      iVar5 = (((uint)((*(int *)(iVar3 + 0x44) - *(int *)(iVar3 + 0x38)) * 0x10) >> 8) *
              (*(ushort *)(&co_sca2ppm + (uint)*(byte *)(iVar3 + 0x5a) * 2) + uVar6)) / 100 + 0x10;
      uVar6 = iVar5 * 2;
      uVar9 = *(int *)(iVar3 + 0x44) - uVar6 / 0x271 & 0xfffffff;
      uVar7 = (uint)*(ushort *)(iVar3 + 0x48) + iVar5 * -2 + (uVar6 / 0x271) * 0x271;
      iVar5 = (int)(short)uVar7;
      if (iVar5 < 0) {
        uVar9 = uVar9 - 1 & 0xfffffff;
        iVar5 = (int)(((uVar7 & 0xffff) + 0x271) * 0x10000) >> 0x10;
      }
      if (*(char *)(iVar3 + 0x57) == '\0') {
        iVar10 = 300;
        if (*(char *)(iVar3 + 0x56) == '\0') {
          iVar10 = 0x1e;
        }
        uVar6 = uVar6 + iVar10;
        if (((uint)(*(int *)(iVar3 + 0x40) * 0x271) >> 1) - 0x96 < uVar6 >> 1) {
          iVar5 = r_sdk_config_get_opts_ext();
          if (((*(uint *)(iVar5 + 0x28) & 0x80) != 0) &&
             (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 3)) {
            r_ble_log_internal_x2
                      (0x40020005,(uint)*(ushort *)(iVar3 + 0x4a) << 0x10 | param_1,uVar6);
          }
          goto _L229;
        }
      }
      *(undefined2 *)(iVar3 + 0x52) = 0;
      bVar1 = *(byte *)(iVar3 + 0x58);
    }
    uVar7 = (uint)_DAT_0001306e;
    *(uint *)(iVar3 + 4) = uVar9;
    uVar2 = *(ushort *)(&lld_sync_max_aux_dur_tab + (uint)bVar1 * 2);
    *(int *)(iVar3 + 8) = iVar5;
    uVar6 = uVar6 * 2 + uVar7 + (uint)uVar2 * 2;
    if (uVar6 < 0x61a81) {
      *(uint *)(iVar3 + 0x10) = uVar6;
    }
    else {
      *(undefined4 *)(iVar3 + 0x10) = 400000;
    }
    r_lld_sync_insert_eco(param_1,acStack_41,acStack_31);
    if (acStack_31[0] != '\0') {
      return;
    }
  } while( true );
}

