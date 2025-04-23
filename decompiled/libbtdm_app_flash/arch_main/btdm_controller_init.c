/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_controller_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 btdm_controller_init(int *param_1)

{
  undefined1 uVar1;
  ushort uVar2;
  undefined2 uVar3;
  int *piVar4;
  char cVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  code *pcVar12;
  uint uVar13;
  int *piVar14;
  undefined4 uVar15;
  undefined1 uStack_24;
  undefined1 uStack_23;
  
  uVar15 = 0xffffffff;
  if (_g_rw_init_sem != 0) goto _L252;
  if (2 < _g_bt_plf_log_level) {
    ets_printf("Rom table is disabled\n");
  }
  (**(code **)(_r_osi_funcs_p + 0xe4))(*(code **)(_r_osi_funcs_p + 0xe4));
  if ((*param_1 == 0x5a5aa5a5) && (param_1[1] == 0x2502230)) {
    if (((((uint)param_1[0xb] >> 0x10) - 1 & 0xff) < 2) &&
       ((((uint)param_1[0xb] >> 0x18) - 1 & 0xff) < 2)) {
      if (*(byte *)(param_1 + 0xc) < 2) {
        *(undefined1 *)(param_1 + 0xc) = 2;
      }
      if (*(ushort *)(param_1 + 0xd) < 0x101) {
        if (*(byte *)((int)param_1 + 0x1e) < 0x10) {
          r_sdk_config_set_opts(param_1);
          sdk_config_set_mask(param_1[8]);
          sdk_config_set_opts_ext(param_1 + 8);
          sdk_config_overwrite_priv_opts();
          sdk_config_set_derived_opts();
          iVar10 = r_sdk_config_get_opts_ext();
          if (*(char *)(iVar10 + 0x1e) == '\0') {
            if (0 < _g_bt_plf_log_level) {
              ets_printf("Controller lib error, need rom lib\n");
            }
            uVar15 = 0xfffffff6;
            goto _L252;
          }
          if ((*(char *)((int)param_1 + 0x17) == '\0') &&
             (iVar10 = r_h4tl_eif_register(param_1[6]), iVar10 != 0)) goto _L257;
          iVar10 = r_sdk_config_get_opts();
          uStack_24 = *(undefined1 *)(iVar10 + 0xd);
          uStack_23 = DAT_00012037;
          r_sdk_config_set_hl_derived_opts(&uStack_24);
          if (((uint)_btdm_env_p >> 0x10 & 0xff) == 0) {
            btdm_hli_get_null_funcs();
          }
          else {
            btdm_hli_get_funcs();
          }
          btdm_hli_funcs_register();
          _btdm_env_p = (int *)(**(code **)(_r_osi_funcs_p + 0x74))
                                         (0x28,*(code **)(_r_osi_funcs_p + 0x74));
          if (_btdm_env_p != (int *)0x0) {
            memset(_btdm_env_p,0,0x28);
            bVar6 = r_lld_env_init();
            bVar7 = r_llm_env_init();
            bVar8 = r_ble_util_buf_env_init();
            bVar8 = bVar6 & bVar7 & bVar8;
            if (((uint)_btdm_env_p >> 8 & 0xff) != 0) {
              bVar6 = r_flash_env_init();
              bVar8 = bVar6 & bVar8;
            }
            iVar10 = r_hci_tl_env_init();
            if ((iVar10 != 0) && (bVar8 != 0)) {
              iVar10 = r_sdk_config_get_opts();
              bVar6 = *(byte *)(iVar10 + 0xd);
              iVar10 = r_sdk_config_get_opts();
              bVar7 = *(byte *)(iVar10 + 0xd);
              uVar13 = (uint)_btdm_env_p >> 0x18;
              iVar10 = r_sdk_config_get_opts();
              piVar14 = _btdm_env_p;
              iVar11 = 0;
              if (((uint)_btdm_env_p >> 0x10 & 0xff) != 0) {
                iVar11 = (uint)*(byte *)(iVar10 + 0xd) * 0x88 + uVar13 * 0xe0;
              }
              pcVar12 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[1] =
                   ((bVar7 + 2) * 0xc + (uint)bVar6 * 0xe6 + 0x25b + iVar11 & 0xfffffffc) + 0xc;
              iVar10 = (*pcVar12)(pcVar12);
              *piVar14 = iVar10;
              iVar10 = r_sdk_config_get_opts();
              piVar14 = _btdm_env_p;
              uVar13 = 0;
              if (((uint)_btdm_env_p >> 0x10 & 0xff) != 0) {
                uVar13 = ((uint)_btdm_env_p >> 0x18) * 400;
                if (uVar13 < 0x1800) {
                  uVar13 = 0x1800;
                }
              }
              pcVar12 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[3] =
                   (((uint)*(byte *)(iVar10 + 0xd) * 0x104 + 0x8ef) * 2 + 0x675 + uVar13 &
                   0xfffffffc) + 0xc;
              iVar10 = (*pcVar12)(pcVar12);
              piVar14[2] = iVar10;
              iVar10 = r_sdk_config_get_opts_ext();
              uVar2 = *(ushort *)(iVar10 + 8);
              iVar10 = r_sdk_config_get_opts_ext();
              piVar14 = _btdm_env_p;
              pcVar12 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[5] =
                   (((uint)*(ushort *)(iVar10 + 6) * 0xc + (uint)uVar2 * 0x10 + 0x293 >> 2) + 3) * 4
              ;
              iVar10 = (*pcVar12)(pcVar12);
              cVar5 = DAT_00012036;
              piVar14[4] = iVar10;
              piVar14 = _btdm_env_p;
              iVar10 = 0xc00;
              if (cVar5 == '\0') {
                iVar10 = 1;
              }
              pcVar12 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[7] = (iVar10 + 3U & 0xfffffffc) + 0xc;
              iVar10 = (*pcVar12)(pcVar12);
              piVar4 = _btdm_env_p;
              piVar14[6] = iVar10;
              if ((((*piVar4 != 0) && (piVar4[2] != 0)) && (piVar4[4] != 0)) &&
                 ((piVar4[7] == 0 || (piVar4[6] != 0)))) {
                if (2 < _g_bt_plf_log_level) {
                  ets_printf("RWIP Heap alloc: ENV [%p %d], MSG [%p %d], NORET [%p %d], DB [%p %d]\n"
                             ,piVar4[1],piVar4[3],piVar4[5],piVar4[6]);
                }
                iVar10 = r_sdk_config_get_opts();
                if ((*(char *)(iVar10 + 0x17) != '\0') &&
                   (iVar10 = r_sdk_config_get_opts(), piVar14 = _btdm_env_p,
                   *(char *)(iVar10 + 0x17) == '\x01')) {
                  iVar10 = (**(code **)(_r_osi_funcs_p + 0x78))
                                     (0xc,*(code **)(_r_osi_funcs_p + 0x78));
                  piVar4 = _btdm_env_p;
                  piVar14[9] = iVar10;
                  if ((void *)piVar4[9] == (void *)0x0) goto _L271;
                  memset((void *)piVar4[9],0,0xc);
                }
                if (2 < _g_bt_plf_log_level) {
                  ets_printf("Uart ENV [%p], VHCI ENV [%p]\n",_btdm_env_p[8],_btdm_env_p[9]);
                }
                _g_rw_init_sem =
                     (**(code **)(_r_osi_funcs_p + 0x24))(1,0,*(code **)(_r_osi_funcs_p + 0x24));
                if (_g_rw_init_sem == 0) {
                  uVar15 = 0xfffffffb;
                }
                else {
                  _g_rw_schd_queue =
                       (**(code **)(_r_osi_funcs_p + 0x4c))(5,8,*(code **)(_r_osi_funcs_p + 0x4c));
                  if (_g_rw_schd_queue == 0) {
                    uVar15 = 0xfffffffa;
                  }
                  else {
                    pcVar12 = *(code **)(_r_osi_funcs_p + 0x24);
                    iVar10 = r_btdm_vnd_ol_task_env_get();
                    uVar15 = (*pcVar12)(1,0);
                    *(undefined4 *)(iVar10 + 8) = uVar15;
                    iVar10 = r_btdm_vnd_ol_task_env_get();
                    if (*(int *)(iVar10 + 8) == 0) {
                      uVar15 = 0xfffffff9;
                    }
                    else {
                      _g_waking_sleeping_sem =
                           (**(code **)(_r_osi_funcs_p + 0x24))(1,*(code **)(_r_osi_funcs_p + 0x24))
                      ;
                      if (_g_waking_sleeping_sem == 0) {
                        return 0xfffffff8;
                      }
                      uVar15 = 0xfffffff7;
                      pcVar12 = *(code **)(_r_osi_funcs_p + 100);
                      iVar10 = r_sdk_config_get_opts();
                      uVar3 = *(undefined2 *)(iVar10 + 8);
                      iVar10 = r_sdk_config_get_opts();
                      uVar1 = *(undefined1 *)(iVar10 + 10);
                      iVar10 = r_sdk_config_get_opts();
                      iVar10 = (*pcVar12)(btdm_controller_task,"btController",uVar3,0,uVar1,
                                          &g_rw_controller_task_handle,*(undefined1 *)(iVar10 + 0xb)
                                         );
                      if (iVar10 == 1) {
                        r_btdm_task_post(7,0,0,1);
                        (**(code **)(_r_osi_funcs_p + 0x34))
                                  (_g_rw_init_sem,10000,*(code **)(_r_osi_funcs_p + 0x34));
                        return 0;
                      }
                    }
                  }
                }
                goto _L252;
              }
            }
          }
_L271:
          r_lld_env_deinit();
          r_llm_env_deinit();
          r_ble_util_buf_env_deinit();
          if (((uint)_btdm_env_p >> 8 & 0xff) != 0) {
            r_flash_env_deinit();
          }
          r_hci_tl_env_deinit();
          if (*_btdm_env_p != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
          }
          if (_btdm_env_p[2] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
          }
          if (_btdm_env_p[4] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
          }
          if (_btdm_env_p[6] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
          }
          piVar14 = _btdm_env_p;
          if (_btdm_env_p[9] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
            piVar14 = _btdm_env_p;
            _btdm_env_p[9] = 0;
          }
          uVar15 = 0xfffffffc;
          (**(code **)(_r_osi_funcs_p + 0x7c))(piVar14,*(code **)(_r_osi_funcs_p + 0x7c));
          _btdm_env_p = (int *)0x0;
          goto _L252;
        }
        if (0 < _g_bt_plf_log_level) {
          pcVar9 = "Default Tx Power Invalid: 0x%x\n";
          goto _L352;
        }
      }
      else if (0 < _g_bt_plf_log_level) {
        pcVar9 = "Invalid scan backoff upperlimitmax: 0x%x\n";
        goto _L352;
      }
    }
    else if (0 < _g_bt_plf_log_level) {
      pcVar9 = "Hardware Target Code Invalid: 0x%x\n";
_L352:
      ets_printf(pcVar9);
    }
  }
  else if (0 < _g_bt_plf_log_level) {
    ets_printf("Config struct mismatch: magic=%08x, ver=%08x\n",0x5a5aa5a5,0x2502230);
  }
_L257:
  uVar15 = 0xfffffffd;
_L252:
  btdm_controller_deinit_internal();
  return uVar15;
}

