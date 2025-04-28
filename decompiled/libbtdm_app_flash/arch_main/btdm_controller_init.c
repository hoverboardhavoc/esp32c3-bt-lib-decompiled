/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  ushort uVar4;
  undefined2 uVar5;
  int *piVar6;
  int *piVar7;
  char cVar8;
  char *pcVar9;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  code *pcVar14;
  undefined1 uStack_24;
  undefined1 uStack_23;
  
  uVar12 = 0xffffffff;
  if (_g_rw_init_sem != 0) goto _L251;
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
            uVar12 = 0xfffffff6;
            if (0 < _g_bt_plf_log_level) {
              ets_printf("Controller lib error, need rom lib\n");
              uVar12 = 0xfffffff6;
            }
            goto _L251;
          }
          if ((*(char *)((int)param_1 + 0x17) == '\0') &&
             (iVar10 = r_h4tl_eif_register(param_1[6]), iVar10 != 0)) goto _L350;
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
            uVar11 = r_lld_env_init();
            iVar10 = r_llm_env_init();
            if (iVar10 == 0) {
              uVar11 = 0;
            }
            iVar10 = r_ble_util_buf_env_init();
            if (iVar10 == 0) {
              uVar11 = 0;
            }
            if ((((uint)_btdm_env_p >> 8 & 0xff) != 0) && (iVar10 = r_flash_env_init(), iVar10 == 0)
               ) {
              uVar11 = 0;
            }
            iVar10 = r_hci_tl_env_init();
            if ((iVar10 != 0) && ((uVar11 & 1) != 0)) {
              iVar10 = r_sdk_config_get_opts();
              bVar1 = *(byte *)(iVar10 + 0xd);
              iVar10 = r_sdk_config_get_opts();
              bVar2 = *(byte *)(iVar10 + 0xd);
              uVar11 = (uint)_btdm_env_p >> 0x18;
              iVar10 = r_sdk_config_get_opts();
              piVar6 = _btdm_env_p;
              uVar13 = (uint)_btdm_env_p >> 0x10 & 0xff;
              if (uVar13 != 0) {
                uVar13 = uVar11 * 0xe0 + (uint)*(byte *)(iVar10 + 0xd) * 0x88;
              }
              pcVar14 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[1] =
                   ((bVar2 + 2) * 0xc + (uint)bVar1 * 0xe6 + 0x25b + uVar13 & 0xfffffffc) + 0xc;
              iVar10 = (*pcVar14)(pcVar14);
              *piVar6 = iVar10;
              iVar10 = r_sdk_config_get_opts();
              piVar6 = _btdm_env_p;
              uVar11 = 0;
              if (((uint)_btdm_env_p >> 0x10 & 0xff) != 0) {
                uVar11 = ((uint)_btdm_env_p >> 0x18) * 400;
                if (uVar11 < 0x1800) {
                  uVar11 = 0x1800;
                }
              }
              pcVar14 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[3] =
                   (((uint)*(byte *)(iVar10 + 0xd) * 0x104 + 0x8ef) * 2 + 0x675 + uVar11 &
                   0xfffffffc) + 0xc;
              iVar10 = (*pcVar14)(pcVar14);
              piVar6[2] = iVar10;
              iVar10 = r_sdk_config_get_opts_ext();
              uVar4 = *(ushort *)(iVar10 + 8);
              iVar10 = r_sdk_config_get_opts_ext();
              piVar6 = _btdm_env_p;
              pcVar14 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[5] =
                   (((uint)*(ushort *)(iVar10 + 6) * 0xc + (uint)uVar4 * 0x10 + 0x293 >> 2) + 3) * 4
              ;
              iVar10 = (*pcVar14)(pcVar14);
              cVar8 = DAT_00012036;
              piVar6[4] = iVar10;
              piVar6 = _btdm_env_p;
              iVar10 = 1;
              if (cVar8 != '\0') {
                iVar10 = 0xc00;
              }
              pcVar14 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[7] = (iVar10 + 3U & 0xfffffffc) + 0xc;
              iVar10 = (*pcVar14)(pcVar14);
              piVar7 = _btdm_env_p;
              piVar6[6] = iVar10;
              if ((((*piVar7 != 0) && (piVar7[2] != 0)) && (piVar7[4] != 0)) &&
                 ((piVar7[7] == 0 || (piVar7[6] != 0)))) {
                if (2 < _g_bt_plf_log_level) {
                  ets_printf("RWIP Heap alloc: ENV [%p %d], MSG [%p %d], NORET [%p %d], DB [%p %d]\n"
                             ,piVar7[1],piVar7[3],piVar7[5],piVar7[6]);
                }
                iVar10 = r_sdk_config_get_opts();
                if ((*(char *)(iVar10 + 0x17) != '\0') &&
                   (iVar10 = r_sdk_config_get_opts(), piVar6 = _btdm_env_p,
                   *(char *)(iVar10 + 0x17) == '\x01')) {
                  iVar10 = (**(code **)(_r_osi_funcs_p + 0x78))
                                     (0xc,*(code **)(_r_osi_funcs_p + 0x78));
                  piVar7 = _btdm_env_p;
                  piVar6[9] = iVar10;
                  if ((void *)piVar7[9] == (void *)0x0) goto _L268;
                  memset((void *)piVar7[9],0,0xc);
                }
                if (2 < _g_bt_plf_log_level) {
                  ets_printf("Uart ENV [%p], VHCI ENV [%p]\n",_btdm_env_p[8],_btdm_env_p[9]);
                }
                _g_rw_init_sem =
                     (**(code **)(_r_osi_funcs_p + 0x24))(1,0,*(code **)(_r_osi_funcs_p + 0x24));
                if (_g_rw_init_sem == 0) {
                  uVar12 = 0xfffffffb;
                }
                else {
                  _g_rw_schd_queue =
                       (**(code **)(_r_osi_funcs_p + 0x4c))(5,8,*(code **)(_r_osi_funcs_p + 0x4c));
                  if (_g_rw_schd_queue == 0) {
                    uVar12 = 0xfffffffa;
                  }
                  else {
                    pcVar14 = *(code **)(_r_osi_funcs_p + 0x24);
                    iVar10 = r_btdm_vnd_ol_task_env_get();
                    uVar12 = (*pcVar14)(1,0);
                    *(undefined4 *)(iVar10 + 8) = uVar12;
                    iVar10 = r_btdm_vnd_ol_task_env_get();
                    if (*(int *)(iVar10 + 8) == 0) {
                      uVar12 = 0xfffffff9;
                    }
                    else {
                      _g_waking_sleeping_sem =
                           (**(code **)(_r_osi_funcs_p + 0x24))
                                     (1,1,*(code **)(_r_osi_funcs_p + 0x24));
                      if (_g_waking_sleeping_sem == 0) {
                        return 0xfffffff8;
                      }
                      uVar12 = 0xfffffff7;
                      pcVar14 = *(code **)(_r_osi_funcs_p + 100);
                      iVar10 = r_sdk_config_get_opts();
                      uVar5 = *(undefined2 *)(iVar10 + 8);
                      iVar10 = r_sdk_config_get_opts();
                      uVar3 = *(undefined1 *)(iVar10 + 10);
                      iVar10 = r_sdk_config_get_opts();
                      iVar10 = (*pcVar14)(btdm_controller_task,"btController",uVar5,0,uVar3,
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
                goto _L251;
              }
            }
          }
_L268:
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
          if (_btdm_env_p[9] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
            _btdm_env_p[9] = 0;
          }
          uVar12 = 0xfffffffc;
          if (_btdm_env_p != (int *)0x0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
            _btdm_env_p = (int *)0x0;
          }
          goto _L251;
        }
        if (0 < _g_bt_plf_log_level) {
          pcVar9 = "Default Tx Power Invalid: 0x%x\n";
          goto _L351;
        }
      }
      else if (0 < _g_bt_plf_log_level) {
        pcVar9 = "Invalid scan backoff upperlimitmax: 0x%x\n";
        goto _L351;
      }
    }
    else if (0 < _g_bt_plf_log_level) {
      pcVar9 = "Hardware Target Code Invalid: 0x%x\n";
_L351:
      ets_printf(pcVar9);
    }
  }
  else if (0 < _g_bt_plf_log_level) {
    ets_printf("Config struct mismatch: magic=%08x, ver=%08x\n",0x5a5aa5a5,0x2502230);
  }
_L350:
  uVar12 = 0xfffffffd;
_L251:
  btdm_controller_deinit_internal();
  return uVar12;
}

